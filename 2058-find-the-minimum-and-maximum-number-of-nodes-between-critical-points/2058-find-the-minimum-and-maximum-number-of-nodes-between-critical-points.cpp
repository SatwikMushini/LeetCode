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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head->next || !head->next->next)return {-1,-1};

        int stCritical = -1;
        int prevCritical = -1;

        ListNode* p1 = head;
        ListNode* p2 = head->next;

        int pos = 1;
        int minDis = 1e9, maxDis = -1;
        while(p2->next){
            if(p1->val < p2->val && p2->val > p2->next->val || p1->val > p2->val && p2->val < p2->next->val){
                if(stCritical == -1){
                    stCritical = pos;
                    prevCritical = pos;
                }
                else{
                    minDis = min(minDis, pos - prevCritical);
                    prevCritical = pos;
                }
            }
            p1 = p1->next;
            p2 = p2->next;
            pos++;
        }
        if(minDis == 1e9)return {-1,-1};
        maxDis = prevCritical - stCritical;
        return {minDis, maxDis};
    }
};