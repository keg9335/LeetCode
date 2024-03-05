/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (!head) return 0;
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    
    while (fast && fast->next) {
        if (fast == slow) return 1;
        fast = fast->next->next;
        slow = slow->next;
    }
    return 0;
}