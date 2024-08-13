#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
#include <stack>



using namespace std;
// runtime: 95%, mem 16%: 

class TrieNode {
public:
    bool isEnd;
    vector<TrieNode*> children;
    TrieNode() : isEnd(false), children(26, nullptr) {};
};


class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* currentNode = root;
        for(char c : word) {
            int index = c - 'a';
            if(currentNode->children[index] == nullptr) {
                currentNode->children[index] = new TrieNode();
            }
            currentNode = currentNode->children[index];
        }
        currentNode->isEnd = true;
        return;
    }
    
    bool search(string word) {
        TrieNode* currentNode = root;
        for(char c : word) {
            int index = c - 'a';
            if(currentNode->children[index] == nullptr) {
                return false;
            }
            currentNode = currentNode->children[index];
        }
        
        return currentNode->isEnd;
        
    }
    
    bool startsWith(string prefix) {
        TrieNode* currentNode = root;
        for(char c : prefix) {
            int index = c - 'a';
            if(currentNode->children[index] == nullptr) {
                return false;
            }
            currentNode = currentNode->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */