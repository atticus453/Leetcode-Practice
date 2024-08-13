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
        unordered_map<char, int> charFrequencyMapS;
        string ans = "";
        if(s.size() < t.size()) return "";
        int tempLength;
        int minLength = INT32_MAX;
        int start = 0;
        for(char c : t) {
            charFrequencyMapT[c] ++;
        }

        for(int end = 0; end < s.size(); end++) {
            charFrequencyMapS[s[end]] ++;

            if(isMapSContainMapT(charFrequencyMapS, charFrequencyMapT)) {
                while(isMapSContainMapT(charFrequencyMapS, charFrequencyMapT)) {
                    charFrequencyMapS[s[start]] --;
                    start ++;
                }
                start --;
                charFrequencyMapS[s[start]] ++;
                tempLength = end - start + 1;
                if(tempLength < minLength) {
                    minLength = tempLength;
                    ans = s.substr(start, tempLength);
                }
            }

        }

        return ans;
    }

    bool isMapSContainMapT(unordered_map<char, int>& MapS, unordered_map<char, int>& MapT) {

        for(auto& [c, freq] : MapT) {
            if(MapS[c] < freq) return false;
        }
        return true;
    }
};