package LinkedListsProblems;

import CtCILibrary.LinkedListNode;


public class deleteDuplicates {
		 
	  // Given a sorted linked list, delete all duplicates such that each element appear only once.
	// works for both unsorted and sorted linked list because the runner pointer runs to the end of the list
	public static void removeDuplicates(LinkedListNode head) {
		if (head == null)
			return;

		LinkedListNode current = head;
		while (current != null) {
			/* Remove all future nodes that have the same value */
			LinkedListNode runner = current;
			while (runner.next != null) {
				if (runner.next.data == current.data) {
					runner.next = runner.next.next;
				} else {
					runner = runner.next;
				}
			}
			current = current.next;
		}

	}
	
    // works for true sorted linked list, but not for unsorted
	public static void removeDuplicates2(LinkedListNode head) {
		if (head == null) {
			return;
		}

		LinkedListNode current = head;
		while (current != null)
		{
			LinkedListNode runner = current;
			while(runner.next != null && runner.next.data == current.data) {
				runner.next = runner.next.next;
			}		
			
			current = current.next;
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		LinkedListNode head = new LinkedListNode(0, null, null);
		head.next = new LinkedListNode(1, null, null);
		head.next.next = new LinkedListNode(2, null, null);
		head.next.next.next = new LinkedListNode(2, null, null);
		head.next.next.next.next = new LinkedListNode(4, null, null);
		head.next.next.next.next.next = new LinkedListNode(2, null, null);
		
		System.out.println(head.printForward());
		removeDuplicates(head); 
		
		System.out.println(head.printForward());
	}

}
