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
    int countSubstrings(string s) {

        int count = 0;
        int localDiameter;
        for(int i=0; i<s.size(); i++) {
            localDiameter = 0;
            while ( i-localDiameter >=0 && i+localDiameter < s.size() && s[i+localDiameter] == s[i-localDiameter]) {
                localDiameter ++;
                count ++; 
            }
        }
        for(int i=0; i<s.size()-1; i++) {
            localDiameter = 0;
            while ( i-localDiameter >=0 && i+localDiameter+1 < s.size() && s[i+localDiameter+1] == s[i-localDiameter]) {
                localDiameter ++;
                count ++; 
            }
        }
        return count;
         
    }
};