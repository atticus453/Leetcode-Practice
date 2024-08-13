#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;
// runtime: 83%, mem: 25%
class TrieNode {
public:
    string endWord;
    vector<TrieNode*> children;
    TrieNode() : endWord(""), children(26, nullptr) {};
};

class Trie {
private:
    

public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        int index;

        TrieNode* currentNode = root;
        for(char c : word) {
            index = c - 'a';
            if(currentNode->children[index] == nullptr) currentNode->children[index] = new TrieNode();
            currentNode = currentNode->children[index];
        }
        currentNode->endWord = word;
    }

    bool search(string word) {
        int index;
        TrieNode* currentNode = root;
        for(char c : word) {
            index = c - 'a';
            if(currentNode->children[index] == nullptr) return false;
            currentNode = currentNode->children[index];
        }
        if(currentNode->endWord.size() == 0) return false;
        return true;  
    }

};

class Solution {
public:


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        Trie* myTrie = new Trie();

        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<string> result;

        for(auto word : words) {
            myTrie->insert(word);
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                buildTrie(i, j, myTrie->root, board, result);
            }
        }




        return result;
    }

    void buildTrie(int i, int j, TrieNode* currentNode, vector<vector<char>>& board, vector<string>& result) {
        // board = m*n
        // visited = m*n
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
            return;
        }

        if(board[i][j] == '#') return;
        char c = board[i][j];
        int index = board[i][j] - 'a';
        if(currentNode->children[index] == nullptr) {
            return;
        } else if(currentNode->children[index]->endWord.size() > 0){
            result.push_back(currentNode->children[index]->endWord);
            currentNode->children[index]->endWord = "";
        }

        board[i][j] = '#';
        if(true) {

            buildTrie(i+1, j, currentNode->children[index], board, result);

        }
        if(true) {

            buildTrie(i-1, j, currentNode->children[index], board, result);

        }
        if(true) {

            buildTrie(i, j+1, currentNode->children[index], board, result);

        }
        if(true) {

            buildTrie(i, j-1, currentNode->children[index], board, result);
        }
        board[i][j] =  c;

        return;
    }
};