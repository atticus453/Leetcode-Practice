#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;
// runtime: 97%, mem: 96%
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
    vector<int> findFrequentTreeSum(TreeNode* root) {

        unordered_map<int, int> count;
        vector<int> sum;
        int maxCount = INT_MIN;
        

        vector<int> ans;
        vector<int> sol;
        calculateSum(root, ans);

        for(auto sum:ans) {
            count[sum]++;
        }

        for(auto [sum, freq]:count) {
            if(freq > maxCount) maxCount = freq;
        }
        
        for(auto& [sum, freq] : count) {
            if(freq == maxCount) sol.push_back(sum);
        }
        return sol;
        
    }

    int calculateSum(TreeNode* root, vector<int>& s) {
        if(root == nullptr) return 0;
        int leftSum = calculateSum(root->left, s);
        int rightSum = calculateSum(root->right, s);
        int Sum = root->val + leftSum + rightSum;
        s.push_back(Sum);
        return Sum;

    }
};