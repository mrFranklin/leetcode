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
    ListNode *reverseList2(ListNode *head) {
        if (head == NULL || head->next) {
            return head;
        }
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return newHead;
    }

    ListNode *reverseList(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *p = head;
        ListNode *q = head->next;
        while (q != NULL) {
            ListNode *tmp = q->next;
            q->next = p;
            p = q;
            q = tmp;
        }
        head->next = NULL;
        return p;
    }
};