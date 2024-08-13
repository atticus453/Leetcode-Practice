#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;
// runtime: 10%, mem: 88%
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.size()) return 0;
        int maxLength = INT_MIN;
        int temp_length;
        // set visited to all digits, space, and special characters
        vector<bool> visited(95, false);
        for(int i=0; i<s.size(); i++) {
            temp_length = lengthFromK(s, i, visited);
            maxLength = max(maxLength, temp_length);
            // set visited to false
            for(int j=0; j<95; j++) {
                visited[j] = false;
            }
        }

        return maxLength;
    }

    int lengthFromK(string& s, int k, vector<bool>& visited) {
        int length = 0;
        for(int i = k; i < s.size(); i++) {
            if(visited[s[i] - ' ']) return length;
            
            visited[s[i] - ' '] = true;
            length ++;
        }
        return length;
    }
};