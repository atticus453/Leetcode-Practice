#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
#include <stack>

using namespace std;
// runtime: 99%, mem: 15%
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
        if(preorder.empty() || inorder.empty()) return nullptr;

        unordered_map<int, int> inorder_map;
        for(int i = 0; i<inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }

        stack<TreeNode*> st;
        TreeNode* root = new TreeNode(preorder[0]);
        st.push(root);
        for(int i=1; i<preorder.size(); i++) {
            TreeNode* node = new TreeNode(preorder[i]);
            if(inorder_map[preorder[i]] < inorder_map[st.top()->val]) {
                st.top()->left = node;
            } else {
                TreeNode* parent;
                while(!st.empty() && inorder_map[preorder[i]] > inorder_map[st.top()->val]) {
                    parent = st.top();
                    st.pop();
                }
                parent->right = node;
            }
            st.push(node);
        }

        return root;
        
        // if (preorder.empty() || inorder.empty()) return nullptr;
        // unordered_map<int, int> inorder_map;
        // for (int i = 0; i < inorder.size(); ++i) {
        //     inorder_map[inorder[i]] = i;
        // }
        // stack<TreeNode*> st;
        // TreeNode* root = new TreeNode(preorder[0]);
        // st.push(root);

        // for (int i = 1; i < preorder.size(); ++i) {
        //     TreeNode* node = new TreeNode(preorder[i]);
        //     if (inorder_map[preorder[i]] < inorder_map[st.top()->val]) {
        //         st.top()->left = node;
        //     } else {
        //         TreeNode* parent = nullptr;
        //         while (!st.empty() && inorder_map[preorder[i]] > inorder_map[st.top()->val]) {
        //             parent = st.top();
        //             st.pop();
        //         }
        //         parent->right = node;
        //     }
        //     st.push(node);
        // }

        // return root;
    }
};