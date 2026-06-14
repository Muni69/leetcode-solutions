class Solution {
public:
    int pairSum(ListNode* head) {
        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Find maximum twin sum
        int ans = 0;
        ListNode* left = head;
        ListNode* right = prev;

        while (right) {
            ans = max(ans, left->val + right->val);
            left = left->next;
            right = right->next;
        }

        return ans;
    }
};