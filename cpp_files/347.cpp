#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;
// runtime: 88%, mem: 59%

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        vector<int> result;
        int temp;
        auto compareFunc = [&freqMap](int a, int b){
            return freqMap[a] < freqMap[b];
        };
        priority_queue<int, vector<int>, decltype(compareFunc)> maxHeap(compareFunc);
        for(int arrayNumber : nums) {
            freqMap[arrayNumber] ++;
        }

        for(auto& [key, val] : freqMap) {
            maxHeap.push(key);
        }

        for(int i=0; i<k; i++) {
            temp = maxHeap.top();
            maxHeap.pop();
            result.push_back(temp);
        }

        return result;

    }
};