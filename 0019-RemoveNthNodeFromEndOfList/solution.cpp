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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || n <= 0) {
            return head;
        }
        ListNode *dummy = new(ListNode);
        dummy->next = head;
        ListNode *slow = dummy, *fast = dummy;
        while (n-- >= 0) {
            // check the n if valid
            if (fast == NULL) {
                return head;
            }
            fast = fast->next;
        }
        // find the right one
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // remove it
        slow->next = slow->next->next;
        return dummy->next;
    }
};