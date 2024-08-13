#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> charFrequencyMapT;

        string ans = "";
        if(s.size() < t.size()) return "";
        int lengthT = 0;
        int tempLength = 0;
        int minLength = INT32_MAX;
        int minLeftBound = 0;
        int start = 0;
        int cnt = 0;
        for(char c : t) {
            charFrequencyMapT[c] ++;
            lengthT ++;
        }

        for(int end = 0; end < s.size(); end++) {
            if(charFrequencyMapT[s[end]] > 0) cnt ++;
            charFrequencyMapT[s[end]] --;

            while(cnt == lengthT) {
                if(end - start + 1 < minLength) {
                    minLeftBound = start;
                    minLength = end - start + 1;
                }
                charFrequencyMapT[s[start]] ++;
                if(charFrequencyMapT[s[start]] > 0) cnt --;
                start ++;
            }

        }
        if(minLength == INT32_MAX) return "";
       ans = s.substr(minLeftBound, minLength);
       return ans;
    }

};