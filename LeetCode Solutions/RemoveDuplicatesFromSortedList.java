/*
 Given a sorted linked list, delete all duplicates such that each element appear only once.
 
 For example,
 Given 1->1->2, return 1->2.
 Given 1->1->2->3->3, return 1->2->3.
 */

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

// O(1) runtime and O(1) space
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        
        ListNode current = head;
        ListNode prev = current;
        while (current != null)
        {
            ListNode next = current.next;
            while (next != null && next.val == current.val)
            {
                next = next.next;
            }
            current = next;
            prev.next = current;
            prev = current;
        }
        
        return head;
    }
}