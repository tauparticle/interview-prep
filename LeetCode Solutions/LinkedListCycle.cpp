// Given a linked list, determine if there is a cycle in it without using extra space

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
    bool hasCycle(ListNode *head) {
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while (fast != NULL && fast->next != NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            
            if (fast == slow) {
                return true;
            }
        }
        
        return false;
        
    }
};