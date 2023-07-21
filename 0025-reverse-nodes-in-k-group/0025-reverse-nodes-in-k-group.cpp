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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* current = head;
        
        while (current != nullptr) {
            if (checkReversible(current, k))
                current = reverseKnodes(current, k);
            else break;
            current = skipKnodes(current, k);
        }
                
        return head;        
    }
private:
    bool checkReversible(ListNode* head, int k) {
        if (k == 1) return true;
        else if (head->next == nullptr) return false;
        else return checkReversible(head->next, k-1);
    }
    
    ListNode* reverseKnodes(ListNode* head, int k) {
        ListNode* current = head;
        for (int i = k-1; i > 0; i=i-2) {
            swapValues(current, i);
            current = current->next;
        }
        return head;
    }
    
    void swapValues(ListNode* head, int k) {
        ListNode* next = head;
        while (k > 0) {
            next = next->next;
            k--;
        }
        int tmp = head->val;
        head->val = next->val;
        next->val = tmp;
    }
    
    ListNode* skipKnodes(ListNode* head, int k) {
        while (k > 0) {
            head = head->next;
            k--;
        }
        return head;
    }
};