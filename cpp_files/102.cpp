// medium
#include <iostream>
#include <limits.h>
#include <queue>
using namespace std;
/*
    normal solution: runtime = 8
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int lengthOfLevel = q.size();
            vector<int> levelNode;
            for(int i=0; i<lengthOfLevel; i++) {
                TreeNode* curNode = q.front();
                q.pop();
                levelNode.push_back(curNode->val);
                if(curNode->left) q.push(curNode->left);
                if(curNode->right) q.push(curNode->right);
            }
            ans.push_back(levelNode);
        }

        return ans;
    }
};