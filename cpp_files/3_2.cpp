#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;
// runtime: 95%, mem: 93 %
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.size()) return 0;
        int maxLength = INT_MIN;
        int temp_length = 0;
        int index;
        int start = 0;
        // set visited to all digits, space, and special characters
        vector<int> visited(95, -1);
        for(int i=0; i<s.size(); i++) {
            index = s[i] - ' ';
            if(visited[index] == -1) {
                visited[index] = i;
                temp_length++;
                maxLength = max(temp_length, maxLength);
            } else {
                temp_length = i - visited[index];
                for(int m = start; m < visited[index]; m++) {
                    visited[(s[m] - ' ')] = -1;
                }
                start = visited[index] + 1;
                visited[index] = i;


            }
        }

        return maxLength;
    }

};