#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
#include <stack>



using namespace std;
// runtime: 90%, mem: 37%
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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans = -1;
        inorderTraversal(root, k, count, ans);
        return ans;
        
    }

    void inorderTraversal(TreeNode* root, int k, int& count, int& ans) {
        if(root == nullptr) return;

        inorderTraversal(root->left, k, count, ans);
        if( ++count == k) {
            ans = root->val;
            return;
        }
        inorderTraversal(root->right, k, count, ans);
    }
};