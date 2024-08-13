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
    int maxSum  = INT_MIN;
    int maxPathSum(TreeNode* root) {
        int ans = maxGain(root, maxSum);
        return maxSum;
    }

private:

    int maxGain(TreeNode* root, int& maxSum) {

        if(!root) return 0;

        int leftGain = max(maxGain(root->left, maxSum), 0);
        int rightGain = max(maxGain(root->right, maxSum), 0);

        int curPathSum = root->val + leftGain + rightGain;

        maxSum = max(maxSum, curPathSum);

        return root->val + max(leftGain, rightGain);
    }

};