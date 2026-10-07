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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        //ListNode *temp = head;
        if(!head || !head->next)return head;
        while(dummy->next && dummy->next->next){
            ListNode *first = dummy->next;
            ListNode *second = dummy->next->next;
            first->next = second->next;
            second->next = first;
            dummy->next = second;
            dummy = first;
        }
        return prev->next;
    }
};