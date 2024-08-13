// hard
#include <iostream>
#include <limits.h>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int, vector<pair<int, int>>> nodeMap; // key: col, value: pair(row, val)
        queue<pair<TreeNode*, pair<int, int>>> BFSQueue; // pair(node, pair(row, col))
        BFSQueue.push({root, {0, 0}});

        while ( !BFSQueue.empty()) {
            pair<TreeNode*, pair<int, int>> q = BFSQueue.front();
            BFSQueue.pop();
            TreeNode* curNode = q.first;
            int row = q.second.first;
            int col = q.second.second;
            nodeMap[col].emplace_back(row, curNode->val); // why not {row, curNode->val}

            if(curNode->left) BFSQueue.push({curNode->left, {row+1, col-1}});
            if(curNode->right) BFSQueue.push({curNode->right, {row+1, col+1}});

        }
        vector<vector<int>> ans;
        for(auto& p : nodeMap){
            auto& vectors = p.second;
            sort(vectors.begin(), vectors.end(), [](const pair<int, int>& a, const pair<int, int>& b){
                if(a.first == b.first) return a.second < b.second;
                return a.first < b.first;
            });
            // sort(vector.begin(), vector.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            //     if(a.first == b.first) return a.second < b.second;
            //     return a.first < b.first;
            // });
            vector<int> col;
            for(auto& node : vectors){
                col.push_back(node.second);
            }
            ans.push_back(col);
        }
        
        return ans;
    }


};