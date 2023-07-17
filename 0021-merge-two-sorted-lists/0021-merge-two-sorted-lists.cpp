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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result;
        
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        
        if (list1->val > list2->val) {
            result = new ListNode(list2->val);
            list2 = list2->next;
        }
        else {
            result = new ListNode(list1->val);
            list1 = list1->next;
        }
        
        ListNode* resultHelper = result;
        
        while(1) {
            if (list1 == nullptr) {
                resultHelper->next = list2;
                break;
            }
            if (list2 == nullptr) {
                resultHelper->next = list1;
                break;
            }
            
            if (list1->val > list2->val) {
                resultHelper->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            else {  
                resultHelper->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            resultHelper = resultHelper->next;
        }
        
        return result;
    }
};