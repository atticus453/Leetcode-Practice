// medium
#include <iostream>
#include <limits.h>
#include <queue>
using namespace std;
/*
    better solution: runtime = 3
*/
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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(root == nullptr) return {};
        queue<TreeNode*> queue_nodes;
        vector<vector<int>> ans;
        queue_nodes.emplace(root);

        while(!queue_nodes.empty()) {
            vector<int> levelOfNodes(queue_nodes.size());
            for(auto& i:levelOfNodes) {
                TreeNode* curNode = queue_nodes.front();
                queue_nodes.pop();
                if(curNode->left != nullptr) queue_nodes.emplace(curNode->left);
                if(curNode->right != nullptr) queue_nodes.emplace(curNode->right);
                i = curNode->val;
            }
            ans.push_back(levelOfNodes);
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(root==nullptr)
        {
            return {};
        }
        vector<vector<int>>level_order_traversal;
        queue<TreeNode*>node_queue;
        node_queue.emplace(root);    
        while(!node_queue.empty())
        {
            vector<int>curr_level(node_queue.size());
            for(auto &i:curr_level)
            {
                TreeNode* node=node_queue.front();
                node_queue.pop();
                i=node->val;
                if(node->left!=nullptr)
                    node_queue.emplace(node->left);
                if(node->right!=nullptr)
                    node_queue.emplace(node->right);
            }
            level_order_traversal.push_back(curr_level);
        }
        return level_order_traversal;
    }
};
