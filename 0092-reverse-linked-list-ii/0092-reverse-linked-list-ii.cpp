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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next || left == right)return head;

        int dis = right - left;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = dummy;

        while(temp && left-- > 1){
            temp = temp->next;
        }
       
        ListNode* first = temp->next;   // we need to attach first->next to the curr
        ListNode* prev = temp->next;
        ListNode* curr = temp->next->next;

        while(dis--){
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        first->next = curr;
        temp->next = prev;
        return dummy->next;

    }
};