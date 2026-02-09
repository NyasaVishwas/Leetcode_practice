/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Compare{
public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for (auto list: lists)
            if (list != nullptr)
                pq.push(list);
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(!pq.empty()){
            ListNode* node = pq.top();
            pq.pop();
            curr->next = node;
            curr = curr->next;
            if (node->next != nullptr)
                pq.push(node->next);
        }
        return dummy->next;
    }
};