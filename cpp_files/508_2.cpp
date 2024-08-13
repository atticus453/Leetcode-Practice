#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>

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
    vector<int> findFrequentTreeSum(TreeNode* root) {

        unordered_map<int, int> count;
        int maxCount;
        calculateSum(maxCount, root, count);

        vector<int> ans;
        for(auto& [sum, freq] : count) {
            if(freq == maxCount) ans.push_back(sum);
        }
        return ans;
        
    }

    int calculateSum(int& maxCount, TreeNode* root, unordered_map<int, int>& count) {

        if(root == nullptr) return 0;
        int leftSum = calculateSum(maxCount, root->left, count);
        int rightSum = calculateSum(maxCount, root->right, count);
        int sum = root->val + leftSum + rightSum;
        count[sum]++;
        maxCount = max(maxCount, count[sum]);
        return sum;

    }
};