package LinkedListsProblems;

import CtCILibrary.LinkedListNode;
import java.util.Stack;

public class ReverseLinkedList {
	
	public static LinkedListNode reverseList(LinkedListNode head) {
		if (head == null) return null;
		Stack<LinkedListNode> s = new Stack<LinkedListNode>();
		
		while (head != null) {
			s.push(head);
			head = head.next;
		}
		
		LinkedListNode dummy = new LinkedListNode(0, null, null);
		dummy.next = s.peek();
		while(!s.empty()) {	
			
			LinkedListNode n = s.pop();
			n.next = s.empty() ? null : s.peek();		
		}
		
		return dummy.next;		
	}
	
	public static LinkedListNode reverseList2(LinkedListNode head) {
		if (head == null) return null;

		LinkedListNode next = head.next;
		LinkedListNode current = head;
		LinkedListNode previous = null;
		
		while(current != null) {
			current.next = previous;
			previous = current;
			current = next;
			if (current != null) {
				next = current.next;
			}
		}
		return previous;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		LinkedListNode head = new LinkedListNode(0, null, null);
		head.next = new LinkedListNode(1, null, null);
		head.next.next = new LinkedListNode(2, null, null);
		head.next.next.next = new LinkedListNode(3, null, null);
		head.next.next.next.next = new LinkedListNode(4, null, null);
		
		System.out.println(head.printForward());
		
		head = reverseList(head);
		System.out.println(head.printForward());
	}

}
