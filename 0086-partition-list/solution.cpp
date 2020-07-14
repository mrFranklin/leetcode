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
    ListNode* partition2(ListNode* head, int x) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        // p：最后一个比x小的值，q：遍历
        ListNode* p = dummy, *q = head, *preq = dummy, *tmp;
        while (q != NULL) {
            if (q->val < x) {
                if (p == preq) {
                    p = q;
                    preq = q;
                    q = q->next;
                } else {
                    // 插入节点
                    tmp = p->next;
                    p->next = q;
                    preq->next = q->next; // 修改q前置节点下个指向
                    q->next = tmp;
                    // 移动p位置
                    p = q;
                    // 移动q节点    
                    q = preq->next;
                }
            } else {
                preq = q;
                q = q->next;
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
    
};