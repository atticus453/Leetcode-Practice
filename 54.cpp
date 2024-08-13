#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;
// runtime: 100%, mem: 15%

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int leftBound = 0;
        int rightBound = matrix[0].size()-1;
        int upBound = 0;
        int downBound = matrix.size()-1;
        vector<int> ans;

         while (true) {

            for(int i = leftBound; i<=rightBound; i++) {
                ans.push_back(matrix[upBound][i]);
            }
            upBound ++;
            if(upBound > downBound) break;


            for(int j=upBound; j<=downBound; j++) {
                ans.push_back(matrix[j][rightBound]);
            }
            rightBound --;
            if(rightBound < leftBound) break;

            for(int i=rightBound; i>=leftBound; i--) {
                ans.push_back(matrix[downBound][i]);
            }
            downBound --;
            if(downBound < upBound) break;

            for(int j=downBound; j>=upBound; j--) {
                ans.push_back(matrix[j][leftBound]);
            }
            leftBound ++;
            if(leftBound > rightBound) break;
        }

        return ans;
        
    }
};