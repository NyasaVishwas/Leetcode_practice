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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        //Time Complexity - number of nodes
        if(!list1) return list2;
        if(!list2) return list1;
        if(list1->val < list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0) return NULL;
        return mergeHelper(lists, 0, n-1);
    }
    ListNode* mergeHelper(vector<ListNode*>& lists, int l, int r){
        if (l==r) return lists[l];
        int mid = l + (r - l)/2;
        auto left = mergeHelper(lists, l, mid);
        auto right = mergeHelper(lists, mid+1, r);
        return mergeTwoLists(left, right);
    }
};