/*
 Remove all elements from a linked list of integers that have value val.
 
 Example
 Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 Return: 1 --> 2 --> 3 --> 4 --> 5
 
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode removeElements(ListNode head, int val) {
        
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode previous = dummy;
        ListNode current = head;
        
        while (current != null)
        {
            if (current.val == val)
            {
                previous.next = current.next;
            }
            else
            {
                previous = previous.next;
            }
            current = current.next;
        }
        
        return dummy.next;
    }
}