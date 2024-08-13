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
        stack<TreeNode*> st;
        TreeNode* current = root;
        int count = 0;

        while(current != nullptr || !st.empty()) {

            while(current != nullptr) {
                st.push(current);
                current = current->left;
            }
            current = st.top();
            st.pop();
            if( ++count == k) {
                return current->val;
            }
            current = current->right;
        }
        return -1;
    }

    
};
