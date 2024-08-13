#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <map>
#include <algorithm>
#include <unordered_set>

using namespace std;
// runtime: 83%, mem: 7%

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        bool firstRow = false;
        bool firstCol = false;

        for(int i=0; i<matrix[0].size(); i++) {
            if(matrix[0][i] == 0) firstRow = true;
        }

        for(int i=0; i<matrix.size(); i++) {
            if(matrix[i][0] == 0) firstCol = true;
        }

        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[i].size(); j++) {
                if(matrix[i][j] == 0){
                    matrix[0][j] = -3;
                    matrix[i][0] = -3;
                }
            }
        }

        for(int i=1; i<matrix[0].size(); i++) {
            if(matrix[0][i] == -3) {
                for(int j=1; j<matrix.size(); j++)
                    matrix[j][i] = 0;
                matrix[0][i] = 0;
            }

        }

        for(int i=1; i<matrix.size(); i++) {
            if(matrix[i][0] == -3) {
                for(int j=1; j<matrix[0].size(); j++) {
                    matrix[i][j] = 0;
                }
                matrix[i][0] = 0;
            }
        }

        if(firstCol) {
            for(int i=0; i<matrix.size(); i++) 
                matrix[i][0] = 0;
        }

        if(firstRow) {
            for(int i=0; i<matrix[0].size(); i++) 
                matrix[0][i] = 0;
        }
        

    }
};