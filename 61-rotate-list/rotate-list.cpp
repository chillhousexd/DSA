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
    ListNode* findNthNode(ListNode* temp, int k) {
        int count = 1;
        while (temp != NULL) {
            if (count == k)
                return temp;
            count++;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0)
            return head;
        int len = 1;
        ListNode* tail = head;

        while (tail->next != NULL) {
            len += 1;
            tail = tail->next;
        }

        if (k % len == 0) {
            return head;
        }

        k = k % len;
        tail->next = head;

        ListNode* newHead = findNthNode(head, len - k);

        head = newHead->next;
        newHead->next = NULL;

        return head;
    }
};