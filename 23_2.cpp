#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// runtime: 89%, mem: 24%
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> ans;
        for(ListNode* currNode : lists) {
            if(currNode) {
                while (currNode)
                {
                    ans.push_back(currNode->val);
                    currNode = currNode->next;
                }
                
            }
        }

        sort(ans.begin(), ans.end());
        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;
        for(int currInt : ans) {
            tail->next = new ListNode(currInt);
            tail = tail->next;
        }

        return dummyHead->next;
    }
};