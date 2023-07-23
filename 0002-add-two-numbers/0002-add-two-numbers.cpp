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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int val = 0, carry = 0;
        ListNode* result = new ListNode();
        ListNode* current = result;
        
        while (l1 || l2 || carry) {
            current->next = new ListNode();
            current = current->next;
            int val1 = l1?l1->val:0, val2 = l2?l2->val:0;
            current->val = (val1 + val2 + carry) % 10;
            carry = (val1 + val2 + carry) / 10;
            l1 = l1? l1->next : nullptr;
            l2 = l2? l2->next : nullptr;
        }
        
        return result->next;
    }
};