#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;
// MLE
class TrieNode {
public:
    bool isEnd;
    vector<TrieNode*> children;
    TrieNode() : isEnd(false), children(26, nullptr) {};
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
        currentNode->isEnd = true;
    }

    bool search(string word) {
        int index;
        TrieNode* currentNode = root;
        for(char c : word) {
            index = c - 'a';
            if(currentNode->children[index] == nullptr) return false;
            currentNode = currentNode->children[index];
        }
        return currentNode->isEnd;    
    }

};

class Solution {
public:


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        Trie* myTrie = new Trie();

        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                visited[i][j] = true;
                buildTrie(i, j, myTrie, "", board, m, n, visited);
                visited[i][j] = false;
            }
        }

        vector<string> result;
        for(string word : words) {
            if(myTrie->search(word)) result.push_back(word);
        }

        return result;
    }

    void buildTrie(int i, int j, Trie* myTrie, string currentWord, vector<vector<char>>& board, int m, int n, vector<vector<bool>>& visited) {
        // board = m*n
        // visited = m*n
        
        currentWord += board[i][j];
        myTrie->insert(currentWord);
        if(i+1 < m && !visited[i+1][j]) {
            visited[i+1][j] = true;
            buildTrie(i+1, j, myTrie, currentWord, board, m, n, visited);
            visited[i+1][j] = false;
        }
        if(i-1 >= 0 && !visited[i-1][j]) {
            visited[i-1][j] = true;
            buildTrie(i-1, j, myTrie, currentWord, board, m, n, visited);
            visited[i-1][j] = false;
        }
        if(j+1 < n && !visited[i][j+1]) {
            visited[i][j+1] = true;
            buildTrie(i, j+1, myTrie, currentWord, board, m, n, visited);
            visited[i][j+1] = false;
        }
        if(j-1 >= 0 && !visited[i][j-1]) {
            visited[i][j-1] = true;
            buildTrie(i, j-1, myTrie, currentWord, board, m, n, visited);
            visited[i][j-1] = false;
        }

        return;
    }
};