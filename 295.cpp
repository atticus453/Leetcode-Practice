#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;
// runtime: TLE

class MedianFinder {
public:

    vector<int> tempArray;
    function<bool(int, int)> compFunc = [](int a, int b){
        return a > b;
    };
    priority_queue<int, vector<int>, function<bool(int, int)>> minHeap;
    
    MedianFinder() : minHeap([](int a, int b){return a > b;}) {};
    void addNum(int num) {
        minHeap.push(num);
    }
    
    double findMedian() {
        int temp;
        vector<double> tempArray;
        int count = minHeap.size();
        double ans;
        if(minHeap.size()%2 == 1) {
            count = count >> 1;
            count ++;
            while(count --) {
                temp = minHeap.top();
                minHeap.pop();
                tempArray.push_back(temp);
            } 
            ans = tempArray[tempArray.size()-1];
        } else {
            count = count >> 1;
            count ++;
            while(count --) {
                temp = minHeap.top();
                minHeap.pop();
                tempArray.push_back(temp);
            } 
            cout << tempArray[tempArray.size()-1] << " " << tempArray[tempArray.size()-2] << endl;
            ans = (tempArray[tempArray.size()-1] + tempArray[tempArray.size()-2]) / 2;
        }
        for(int i = 0; i < tempArray.size(); i++) {
            minHeap.push(tempArray[i]);
        }
        return ans;
    }
};



/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */