package LinkedListsProblems;

import CtCILibrary.LinkedListNode;

public class DeleteAllDuplicates2 {
	
	// given sorted linked list, remove all elements which have duplicate values
	public static LinkedListNode deleteDuplicates(LinkedListNode head) {
        if (head == null) return null;
        if (head.next == null) return head;
        LinkedListNode runner = head.next;
        int count = 0;
        while(runner != null && runner.data == head.data) {
            runner = runner.next;
            count++;
        }
        LinkedListNode post = deleteDuplicates(runner);
        if (count > 0) return post;
        head.next = post;
        return head;
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		LinkedListNode head = new LinkedListNode(1, null, null);
		head.next = new LinkedListNode(1, null, null);
		head.next.next = new LinkedListNode(2, null, null);
		head.next.next.next = new LinkedListNode(2, null, null);
		head.next.next.next.next = new LinkedListNode(4, null, null);
				
		System.out.println(head.printForward());
		head = deleteDuplicates(head); 
		
		System.out.println(head.printForward());
		
		LinkedListNode head2 = new LinkedListNode(0, null, null);
		head2.next = new LinkedListNode(1, null, null);
		head2.next.next = new LinkedListNode(2, null, null);
		head2.next.next.next = new LinkedListNode(2, null, null);
						
		System.out.println(head2.printForward());
		head2 = deleteDuplicates(head2); 
		
		System.out.println(head2.printForward());
		
		LinkedListNode head3 = new LinkedListNode(0, null, null);
		head3.next = new LinkedListNode(0, null, null);
		head3.next.next = new LinkedListNode(2, null, null);
		head3.next.next.next = new LinkedListNode(2, null, null);
						
		System.out.println(head3.printForward());
		head3 = deleteDuplicates(head3); 
		
		System.out.println(head3 == null ? "null" : head3.printForward());
	}

}
