/*Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Hide Company Tags Amazon LinkedIn Apple Microsoft
Hide Tags Linked List
Hide Similar Problems (H) Merge k Sorted Lists (E) Merge Sorted Array (M) Sort List (M) Shortest Word Distance II
Have you met this question in a real interview? Yes  No
Discuss
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* dummy = new ListNode(0);
        
        ListNode* current = dummy;
        
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                current->next = l1;
                l1 = l1->next;
            }
            else
            {
                current->next = l2;
                l2 = l2->next;
            }
            
            current = current->next;
            current->next = nullptr;
            
        }
        
        if (l1 != nullptr)
        {
            current->next = l1;
        }
        else if (l2 != nullptr)
        {
            current->next = l2;
        }
        
        return dummy->next;
        
    }
};