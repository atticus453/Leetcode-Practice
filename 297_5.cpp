#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;
// runtime: 96.4% memory: 75%
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Codec {
public:

    string serializeHelper(TreeNode* root, string& s) {
        queue<TreeNode*> q;
        q.emplace(root);
        s += to_string(root->val);
        s += ",";
        while (!q.empty()) {
            TreeNode* currentNode = q.front();
            q.pop();
            if(currentNode->left) {
                s += to_string(currentNode->left->val);
                s += ",";
                q.emplace(currentNode->left);
            } else s += "#,";

            if(currentNode->right) {
                s += to_string(currentNode->right->val);
                s += ",";
                q.emplace(currentNode->right);
            } else s += "#,";
        }

        return s;
        
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "";
        string s = "";
        serializeHelper(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return nullptr;
        stringstream ss(data);
        queue<TreeNode*> q;
        string nodeValue;
        getline(ss, nodeValue, ',');
        TreeNode* temp = new TreeNode(stoi(nodeValue));
        q.emplace(temp);
        
        while (!q.empty()) {
            TreeNode* currentNode = q.front();
            q.pop();
            getline(ss, nodeValue, ',');
            if(nodeValue == "#") {
                currentNode->left = nullptr;
            } else {
                currentNode->left = new TreeNode(stoi(nodeValue));
                q.emplace(currentNode->left);
            }

            getline(ss, nodeValue, ',');
            if(nodeValue == "#") {
                currentNode->right = nullptr;
            } else {
                currentNode->right = new TreeNode(stoi(nodeValue));
                q.emplace(currentNode->right);
            }
        }

        return temp;
        
        
    }
};