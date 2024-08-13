#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
#include <stack>



using namespace std;
// runtime: 86%, mem: 99%
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


        ans = isAncestor(root, small, big);
        return ans;
        
    }

    TreeNode* isAncestor(TreeNode*root, int small, int big) {

        if(root == nullptr) return nullptr;
        if( root->val >= small && root->val <= big) return root;


        TreeNode* left = nullptr;
        TreeNode* right = nullptr;
        if(root->val >= big) {
            left = isAncestor(root->left, small, big);
            return left;
        } 
        if(root->val <= small) {
            right =  isAncestor(root->right, small, big);
            return right;
        }
        return nullptr;
    }

};