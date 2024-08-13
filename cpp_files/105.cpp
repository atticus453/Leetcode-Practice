#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;
// 
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        
        if(preorder.size() == 0) return nullptr;
        int rootVal = preorder[0];
        if(preorder.size() == 1) {
            TreeNode* root = new TreeNode(rootVal);
            root->left = nullptr;
            root->right = nullptr;
            return root;
        }
        TreeNode* root = new TreeNode(rootVal);
        vector<int> preLeft;
        vector<int> preRight;
        vector<int> inLeft;
        vector<int> inRight;
        bool flag = false;
        for(auto i:inorder) {
            if(i == rootVal) {
                flag = true;
                continue;
            }
            if(!flag) {
                inLeft.push_back(i);
            } else {
                inRight.push_back(i);
            }
        }
        int vectorSize = inLeft.size();
        for(int i=1; i<inorder.size(); i++) {
            if(i <= vectorSize) {
                preLeft.push_back(preorder[i]);
            } else {
                preRight.push_back(preorder[i]);
            }
        }

        root->left = buildTree(preLeft, inLeft);
        root->right = buildTree(preRight, inRight);
        return root;
    }
};