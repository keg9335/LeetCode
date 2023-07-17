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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k = 0;
        ListNode* current = head;
        
        while (current != nullptr) {
            k++;
            current = current->next;
        }
        
        if (k == n) head = head->next;
        else {
            k = k - n;
            current = head;

            for (int i = 0; i < k - 1; i++) {
                current = current->next;
            }

            ListNode* tmp = current->next;
            current->next = current->next->next;
            delete tmp;
        }
        return head;
    }
};