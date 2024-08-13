#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
#include <stack>



using namespace std;
// code wrong 
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue<TreeNode*> queue_nodes;
        TreeNode* current;
        queue_nodes.push(root);
        TreeNode* ans;
        int small;
        int big;
        if(p->val > q->val) {
            big = p->val;
            small = q->val;
        } else {
            big = q->val;
            small = p->val;
        }


        while(!queue_nodes.empty()) {
            current = queue_nodes.front();
            queue_nodes.pop();
            ans = isAncestor(current, small, big);
            if(ans != nullptr) return ans;

            if(current->left && current->val > big) queue_nodes.push(current->left);
            if(current->right && current->val < small) queue_nodes.push(current->right);

        }
        return ans;
        
    }

    TreeNode* isAncestor(TreeNode* root, int small, int big) {
        if(root->val <= big && root->val >= small) {
            return root;
        }

        return nullptr;

    }
};