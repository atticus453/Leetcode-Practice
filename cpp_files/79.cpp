#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int width = board[0].size();
        int height = board.size();
        bool ans_find = false;
        for(int i=0; i<height; i++) {
            for(int j=0; j<width; j++) {
                ans_find = ans_find || sequentialFind(board, word, 0, i, j);
                if(ans_find) return true;
            }
        }

        return ans_find;
        
    }

    bool sequentialFind(vector<vector<char>>& board, string word, int index, int h_index, int w_index) {

        int width = board[0].size();
        int height = board.size();
        bool ans = false;
        char c = board[h_index][w_index];
        if(board[h_index][w_index] == word[index] && board[h_index][w_index] != '#' ) {
            
            if(index == word.length()-1) return true;
            board[h_index][w_index] = '#';
            if(h_index+1 < height) {
                ans = ans || sequentialFind(board, word, index+1, h_index+1, w_index);
            }

            if(h_index-1 >= 0) {
                ans = ans || sequentialFind(board, word, index+1, h_index-1, w_index);
            }

            if(w_index+1 < width) {
                ans = ans || sequentialFind(board, word, index+1, h_index, w_index+1);
            }

            if(w_index-1 >= 0) {
                ans = ans || sequentialFind(board, word, index+1, h_index, w_index-1);
            }

            board[h_index][w_index] = c;
        } else {
            return false;
        }

        return ans;

        // ans = ans || sequentialFind(board, word, index, h_index+1, w_index);
        // ans = ans || sequentialFind(board, word, index, h_index-1, w_index);
        // ans = ans || sequentialFind(board, word, index, h_index, w_index+1);
        // ans = ans || sequentialFind(board, word, index, h_index, w_index-1);
    }
};