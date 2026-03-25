/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* curr = dummy;
        
        while (curr->next != NULL) {
            if (curr->next->val == val) {
                curr->next = curr->next->next; // remove node
            } else {
                curr = curr->next; // move forward
            }
        }
        
        return dummy->next;
    }
};