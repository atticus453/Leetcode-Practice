#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;
// runtime: 17.45%, mem: 13.99% 
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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // preorder traversal
        if(!root) return "null ";
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeHelper(ss);
    }

    TreeNode* deserializeHelper(stringstream& ss) {

        string item;
        ss >> item;
        if(item == "null") return nullptr;
        TreeNode* node = new TreeNode(stoi(item));
        node->left = deserializeHelper(ss);
        node->right = deserializeHelper(ss);

        return node;


    }
};


// int main() {
//     TreeNode* root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(3);
//     root->right->left = new TreeNode(4);
//     root->right->right = new TreeNode(5);

//     Codec ser, deser;
//     TreeNode* ans = deser.deserialize(ser.serialize(root));
//     return 0;
// }
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// compile: g++ -std=c++11 297.cpp -o 2970 