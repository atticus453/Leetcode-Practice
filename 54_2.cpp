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
    vector<int> ans;
    if (matrix.empty()) return ans;

    int top = 0;
    int down = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;

    while (top <= down && left <= right) {
        // Traverse from left to right
        for (int i = left; i <= right; ++i) {
            ans.push_back(matrix[top][i]);
        }
        top++;

        // Traverse from top to bottom
        for (int i = top; i <= down; ++i) {
            ans.push_back(matrix[i][right]);
        }
        right--;

        if (top <= down) {
            // Traverse from right to left
            for (int i = right; i >= left; --i) {
                ans.push_back(matrix[down][i]);
            }
            down--;
        }

        if (left <= right) {
            // Traverse from bottom to top
            for (int i = down; i >= top; --i) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;
}

};