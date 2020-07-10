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
    ListNode* swapPairs2(ListNode* head) {
        ListNode *p = head;
        ListNode *q = head->next;
        ListNode *dummy = new(ListNode);
        dummy->next = head;
        ListNode *pre = dummy;
        while (p != NULL && q != NULL) {
            ListNode *tmp = q->next;
            q->next = p;
            pre->next = q;
            p->next = tmp;
            if (tmp == NULL || tmp->next == NULL) {
                break;
            }
            pre = p;
            p = tmp;
            q = p->next;
        }
        return dummy->next;
    }

    // good
    ListNode* swapPairs3(ListNode* head) {
        ListNode *dummy = new(ListNode);
        dummy->next = head;
        ListNode *pre = dummy;
        while (head != NULL && head->next != NULL) {
            // set two pointer for the swapping
            ListNode *p = head;
            ListNode *q = head->next;
            // swap
            p->next = q->next;
            pre->next = q;
            q->next = p;
            // move the pointer
            pre = head;
            head = p->next;
        }
        return dummy->next;
    }

    // good
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *p = swapPairs(head->next->next);
        ListNode *tmp = head->next;
        head->next->next = head;
        head->next = p;

        return tmp;
    }
};