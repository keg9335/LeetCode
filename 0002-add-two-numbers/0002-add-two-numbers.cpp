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
        ListNode* nullNode = new ListNode();
        
        while (1) {
            val = (l1->val + l2->val + carry) % 10;
            current->val = val;
            carry = (l1->val + l2->val + carry) / 10;
            if (l1->next == nullptr && l2->next == nullptr 
                && carry == 0) break;
            current->next = new ListNode();
            current = current->next;
            l1 = l1->next == nullptr? nullNode : l1->next;
            l2 = l2->next == nullptr? nullNode : l2->next;
        }
        
        return result;
    }
};