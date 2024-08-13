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
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, function<bool(int, int)>> minHeap;
    
    MedianFinder() : minHeap([](int a, int b){return a > b;}) {};
    void addNum(int num) {
        int temp;
        if(minHeap.empty() && maxHeap.empty()) maxHeap.push(num);
        else if(minHeap.size() < maxHeap.size()) {
            if(num > maxHeap.top()) minHeap.push(num);
            else {
                temp = maxHeap.top();
                maxHeap.pop();                
                maxHeap.push(num);
                minHeap.push(temp);
            }
        }
        else {
            if(num < maxHeap.top()) maxHeap.push(num);
            else{
                temp = minHeap.top();
                minHeap.pop();
                maxHeap.push(temp);
                minHeap.push(num);

            }
        }
        
    }
    
    double findMedian() {
        double ans;
        double ans_2;
        if(minHeap.size() <  maxHeap.size()) ans = maxHeap.top();
        else {
            ans = minHeap.top();
            ans_2 = maxHeap.top();
            ans += ans_2;
            ans /= 2;
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