
/**
Given a non-negative number represented as a singly linked list of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Example:
Input:
1->2->3

Output:
1->2->4
Hide Company Tags Google
Hide Tags Linked List
Hide Similar Problems (E) Plus One


 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    
struct PartialSum
{
    ListNode* sum;
    int carry;
    
    PartialSum(int c)
    {
        sum = nullptr;
        carry = c;
    }
};
    
public:
    ListNode* plusOne(ListNode* head) {
        PartialSum* ps = plusOneHelper(head);
        
        ListNode* result =  ps->sum;
        
        if (ps->carry > 0)
        {
            result = insertInFront(result, 1);
        }
        
        delete ps;
        return result;
        
    }
    
    ListNode* insertInFront(ListNode* node, int val)
    {
        ListNode* n = new ListNode(val);
        n->next = node;
        return n;
    }
    
    PartialSum* plusOneHelper(ListNode* head)
    {
        if (!head)
        {
            return new PartialSum(1);
        }
        
        PartialSum* ps = plusOneHelper(head->next);
        
        int sum = head->val + ps->carry;
        ListNode* runningSum = insertInFront(ps->sum, sum % 10);
        
        ps->sum = runningSum;
        ps->carry = sum / 10;
        
        return ps;
    }
};

