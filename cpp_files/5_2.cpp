#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;
// runtime: 95%, mem: 66%

class Solution {
public:
    string longestPalindrome(string s) {
        int LengthOfStr = s.size();
        if (LengthOfStr == 1) {
            return s;
        }
        int Start = 0, LengthOfSubStr = 1;
        for (int CharIterator = 0; CharIterator < LengthOfStr;) {
            if (LengthOfStr - CharIterator < LengthOfSubStr / 2) {
                break;
            }
            int LeftBorder = CharIterator, RightBorder = CharIterator;
            while (RightBorder < LengthOfStr - 1 &&
                   s[RightBorder] == s[RightBorder + 1]) {
                RightBorder++;
            }
            CharIterator = RightBorder + 1;
            while (RightBorder < LengthOfStr - 1 && LeftBorder > 0 &&
                   s[RightBorder + 1] == s[LeftBorder - 1]) {
                RightBorder++;
                LeftBorder--;
            }
            int LeftToRightLen = RightBorder - LeftBorder + 1;
            if (LeftToRightLen > LengthOfSubStr) {
                Start = LeftBorder;
                LengthOfSubStr = LeftToRightLen;
            }
        }
        return s.substr(Start, LengthOfSubStr);
    }
};