#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
#include <stack>

using namespace std;
// runtime: 60%, mem:
class TrieNode {
public:
    bool isEnd;
    vector<TrieNode*> children;
    TrieNode(): isEnd(false), children(26, nullptr) {};

};
class WordDictionary {
private:
    TrieNode* root;
public:
    WordDictionary() {
        this->root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* currentNode = root;
        int index;
        for(int i=0; i<word.size(); i++) {
            index = word[i] - 'a';
            if(currentNode->children[index] == nullptr) {
                currentNode->children[index] = new TrieNode();
            }
            currentNode = currentNode->children[index];
        }
        currentNode->isEnd = true;
        return;
    }
    
    bool search(string word) {
        return searchHelper(word, root);
    }

    bool searchHelper(string word, TrieNode* rootNow) {
        TrieNode* currentNode = rootNow;
        for(int i=0; i<word.size(); i++) {
            if(word[i] == '.') {
                bool flag = false;
                for(TrieNode* j : currentNode->children) {
                    if(j) flag = flag || searchHelper(word.substr(i+1), j);
                }
                return flag;
            } else {
                int index = word[i] - 'a';
                if(currentNode->children[index] == nullptr) return false;
                currentNode = currentNode->children[index];
            }
        }
        return currentNode->isEnd;
    }
};
