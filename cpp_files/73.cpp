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
        unordered_set<int> zeroRow;
        unordered_set<int> zeroCol;

        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[i].size(); j++) {
                if(matrix[i][j] == 0){
                    zeroCol.insert(j);
                    zeroRow.insert(i);
                }
            }
        }

        for(int clearRow : zeroRow) {
            for(int i=0; i<matrix[clearRow].size(); i++) {
                matrix[clearRow][i] = 0;
            }
        }

        for(int clearCol : zeroCol) {
            for(int i=0; i<matrix.size(); i++) {
                matrix[i][clearCol] = 0;
            }
        }
        

    }
};