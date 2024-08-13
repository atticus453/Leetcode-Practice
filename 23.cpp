#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// runtime: 93%, mem: 64%
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Lambda function to compare two ListNode pointers
        auto comp = [](ListNode* a, ListNode* b) { return a->val > b->val };
        
        // Priority queue (min-heap) using the custom comparator
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> minHeap(comp);
        
        // Initialize the heap with the head of each list
        for(ListNode* node : lists) {
            minHeap.push(node);
        }

        // Dummy head for the result list
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        // Merge the lists
        while (!minHeap.empty()) {
            ListNode* temp = minHeap.top();
            minHeap.pop();

            if(temp->next) minHeap.push(temp->next);

            tail->next = temp;
            tail = temp;
        }

        // Return the merged list
        return dummy->next;
    }
};
