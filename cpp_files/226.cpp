#include <iostream>
#include <limits.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if(!root) return nullptr;

        TreeNode* leftChild = invertTree(root->left);
        TreeNode* rightChild = invertTree(root->right);
        
        root->left = rightChild;
        root->right = leftChild;

        return root;
    }
};