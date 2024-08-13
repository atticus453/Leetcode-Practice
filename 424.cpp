#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;
// runtime: 70%, mem: 15%

class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char, int> charFrequencyMap;
        int start = 0;
        int maxLength = 0;
        int tempLength = 0;
        char mostPopularChar;
        int timesMostPopular = 0;
        int currentK;
        for(int i = 0; i < s.size(); i++) {

            charFrequencyMap[s[i]] ++;
            timesMostPopular = 0;
            currentK = 0;
            for(auto [c, times] : charFrequencyMap) {
                timesMostPopular = max(times, timesMostPopular);
                currentK += times;
            }

            currentK -= timesMostPopular;

            if(currentK <= k) {
                tempLength = i - start + 1;
                maxLength = max(maxLength, tempLength);
            } else {
                while (currentK > k)
                {
                    charFrequencyMap[s[start]] --;
                    start ++;
                    timesMostPopular = 0;
                    currentK = 0;
                    for(auto [c, times] : charFrequencyMap) {
                        timesMostPopular = max(times, timesMostPopular);
                        currentK += times;
                    }
                    currentK -= timesMostPopular;
                }
            }
            
            
        }
        return maxLength;
        
    }


};