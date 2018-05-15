/*You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

*/

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        return AddTwoNumbersWithCarry(l1, l2, 0);
    }
    
    ListNode *AddTwoNumbersWithCarry(ListNode *l1, ListNode *l2, int carry) {
        
        if (l1 == NULL && l2 == NULL && carry == 0) return NULL;
        
        int sum = carry;
        if (l1 != NULL) sum += l1->val;
        if (l2 != NULL) sum += l2->val;
 
        
        ListNode* result = new ListNode(sum % 10);
        result->next = AddTwoNumbersWithCarry(l1 == NULL ? NULL : l1->next,
                                              l2 == NULL ? NULL : l2->next,
                                              sum >= 10 ? 1 : 0);
        return result;
    }
};