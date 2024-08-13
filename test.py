import torch
from torch import nn

class NestedTensor:
    def __init__(self, tensor, mask=None):
        self.tensor = tensor
        self.mask = mask

    def to(self, device):
        return NestedTensor(self.tensor.to(device), self.mask.to(device) if self.mask is not None else None)

class PositionEmbedding(nn.Module):
    def forward(self, x):
        B, C, H, W = x.shape
        pos = torch.randn(B, C, H, W)
        return pos

class Joiner(nn.Sequential):
    def __init__(self, backbone, position_embedding):
        super().__init__(backbone, position_embedding)

    def forward(self, tensor_list: NestedTensor):
        xs = self[0](tensor_list.tensor)
        out = []
        pos = []
        for name, x in xs.items():
            out.append(x)
            pos.append(self[1](x).to(x.dtype))
        return out, pos

# 模擬骨幹網絡的輸出
class MockBackbone(nn.Module):
    def forward(self, x):
        return {
            'layer1': torch.randn(1, 64, 56, 56),
            'layer2': torch.randn(1, 128, 28, 28),
            'layer3': torch.randn(1, 256, 14, 14),
            'layer4': torch.randn(1, 512, 7, 7)
        }

# 初始化 Joiner
backbone = MockBackbone()
position_embedding = PositionEmbedding()
joiner = Joiner(backbone, position_embedding)

# 構建輸入 NestedTensor
input_tensor = torch.randn(1, 3, 224, 224)
input_nested_tensor = NestedTensor(input_tensor)

# 前向傳播
out, pos = joiner(input_nested_tensor)

# 查看輸出
print("Output feature maps:")
for i, feature_map in enumerate(out):
    print(f"Feature map {i}: shape {feature_map.shape}")

print("Position embeddings:")
for i, position in enumerate(pos):
    print(f"Position embedding {i}: shape {position.shape}")
