#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;
// runtime: 92%, mem: 66%
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size()) return false;
        vector<int> countArr(96, 0);
        for(int i = 0; i < s.size(); i++) {
            countArr[s[i] - ' '] ++;
            countArr[t[i] - ' '] --;
        }

        for(int k : countArr) {
            if( k != 0) return false;
        }


        return true;
    }
};