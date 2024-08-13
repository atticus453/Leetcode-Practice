#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
#include <stack>

using namespace std;
// runtime: 97%, mem: 61%
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
    bool isValidBST(TreeNode* root) {

        return checkBST(root, LLONG_MIN, LLONG_MAX);
    }

    bool checkBST(TreeNode* root, long long int lower, long long int upper) {
        if(root == nullptr) return true;

        if(root->val <= lower || root->val >= upper) return false;

        return checkBST(root->left, lower, root->val) && checkBST(root->right, root->val, upper);

    }
};