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
    ListNode* deleteDuplicates1(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *dummy = new(ListNode);
        dummy->next = head;
        ListNode *p = head, *q = head->next, *pre = dummy;
        while (p != NULL) {
            bool dupl = false;
            while (q != NULL && p->val == q->val) {
                dupl = true;
                q = q->next;
            }

            if (!dupl) {
                pre = p;
            }
            p = q;
            pre->next = p;
            if (q == NULL) {
                break;
            }
            q = q->next;
        }

        return dummy->next;
    }

    // good
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new(ListNode);
        dummy->next = head;
        ListNode *p = dummy;
        while (p->next != NULL && p->next->next != NULL) {
            if (p->next->val == p->next->next->val) {
                ListNode *tmp = p->next;
                while (tmp->next != NULL && tmp->val == tmp->next->val) {
                    tmp = tmp->next;
                }
                p->next = tmp->next;
            } else {
                p = p->next;
            }
        }

        return dummy->next;
    }
};