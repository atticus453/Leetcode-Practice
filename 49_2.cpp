#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
#include <map>


using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<vector<int>, vector<string>> countMap;
        for(string currStr : strs) {
            vector<int> countArr(26, 0);
            for(char c : currStr) {
                countArr[c - 'a']++;
            }
            countMap[countArr].push_back(currStr);
        }
        for(auto& [key, value] : countMap) {
            ans.push_back(value);
        }
        return ans;
    }
};