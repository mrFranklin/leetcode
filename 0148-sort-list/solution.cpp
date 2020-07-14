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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new(ListNode);
        ListNode* p = head;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1 != NULL) {
            p->next = l1;
        } else {
            p->next = l2;
        }

        return head->next;
    }

    // 归并排序，用到了递归，up-to-bottom
    ListNode* sortList2(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pre = NULL;
        while (fast != NULL && fast->next != NULL) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        pre->next = NULL;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        return mergeTwoLists(l1, l2);
    }

    ListNode* cut(ListNode* head, int n) {
        ListNode* p = head;
        while (--n > 0 && p != NULL) {
            p = p->next;
        }
        if (p == NULL) {
            return NULL;
        }
        ListNode* tail = p->next;
        p->next = NULL;

        return tail;
    }

    // 归并排序，bottom-to-up
    ListNode* sortList3(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode* p = head;
        int len = 0;
        while (p != NULL) {
            p = p->next;
            len++;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* tail = dummy;
        ListNode* first, *second, *next;
        for (int size = 1; size < len; size *= 2) {
            tail = dummy;
            next = dummy->next;
            while (next) {
                first = next;
                second = cut(first, size);
                next = cut(second, size);
                tail->next = mergeTwoLists(first, second);
                while (tail->next != NULL) {
                    tail = tail->next;
                }
            }
        }
        return dummy->next;
    }

    ListNode* partition(ListNode* head, int x) {
        ListNode* first = new ListNode(0);
        ListNode* second = new ListNode(0);
        ListNode* firstP = first;
        ListNode* secondP = second;
        while (head) {
            if (head->val < x) {
                firstP->next = head;
                firstP = firstP->next;
            } else {
                secondP->next = head;
                secondP = secondP->next;
            }
            head = head->next;
        }
        firstP->next = second->next;
        secondP->next = NULL;
        return first->next;
    }
    // 快排
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        } 
        ListNode* first = partition(head, head->val);

        ListNode* right = sortList(head->next);
        head->next = NULL;
        ListNode* left = sortList(first);

        head = left;
        while (left->next) {
            left = left->next;
        }
        left->next = right;

        return head;
    }
};