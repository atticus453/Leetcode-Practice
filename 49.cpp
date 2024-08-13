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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groupByLength(10000);
        vector<vector<string>>  ans;
        for(string currStr : strs) {
            groupByLength[currStr.size()].push_back(currStr);
        }

        for(auto& vectorStr : groupByLength) {
            vector<int> visited(vectorStr.size(), -1);
            for(int i =0; i < vectorStr.size(); i++) {
                if(visited[i] != -1) continue;;
                vector<string> now;
                now.push_back(vectorStr[i]);
                visited[i] = 1;
                for(int j = i+1; j < vectorStr.size(); j++) {
                    if(visited[j] != -1) continue;
                    if(isAnagram(vectorStr[i], vectorStr[j])){
                        now.push_back(vectorStr[j]);
                        visited[j] = 1;
                    } 
                }
                ans.push_back(now);
                
            }
        }

        return ans;
    }



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