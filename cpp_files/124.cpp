#include <iostream>
#include <limits.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum  = INT_MIN;
        maxGain(root, maxSum);

        return maxSum;
    }

private:
    int maxGain(TreeNode* root, int& maxSum) {

        if(root == nullptr) {
            return 0;
        }

        int leftGain = max(maxGain(root->left, maxSum), 0);
        int rightGain = max(maxGain(root->right, maxSum), 0);

        int currPathSum = root->val + leftGain + rightGain;
        // we update the max path sum here
        maxSum = max(maxSum, currPathSum);

        return root->val + max(leftGain, rightGain);



    }
};