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
    string longestPalindrome(string s) {
        
        if(s.length() == 1) return s;
        int maxLength = INT_MIN;
        int localDiameter;
        int leftIndex;
        int tempLength;
        for(int i =0; i<s.size(); i++) {
            localDiameter = 0;
            while( i - localDiameter >= 0 and i + localDiameter < s.size() && s[i-localDiameter] == s[i+localDiameter]) {
                localDiameter ++;
            }
            localDiameter --;
            tempLength = localDiameter*2 + 1;
            if(tempLength > maxLength) {
                maxLength = max(tempLength, maxLength);
                leftIndex = i - localDiameter;
            }   
        }

        for(int i =0; i<s.size()-1; i++) {
            if(s[i] != s[i+1]) continue;

            localDiameter = 0;
            while( i - localDiameter >= 0 and i + localDiameter + 1 < s.size() && s[i-localDiameter] == s[i+localDiameter+1]) {
                localDiameter ++;
            }
            tempLength = localDiameter*2;
            if(tempLength > maxLength) {
                maxLength = max(tempLength, maxLength);
                leftIndex = i - localDiameter + 1;
            }   
        }

        return s.substr(leftIndex, maxLength);

        
        
    }
};