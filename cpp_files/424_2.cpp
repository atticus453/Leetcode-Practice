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
    int characterReplacement(string s, int k) {
        vector<int> c(26);
        int maxC=0;
        int l=0;
        int r=0;
        int sum=0;
        while(r < s.size()){
            c[s[r]-'A']++;
         maxC=max(maxC,c[s[r]-'A']);

        
        if(r-l+1-maxC >k){
            c[s[l]-'A']--;
            l++;
        }
        sum=max(sum,r-l+1);
        r++;
        }
        return sum;
    }
};