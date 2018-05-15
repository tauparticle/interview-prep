using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.LinkedList
{
    public static class ReverseLinkedList
    {
        public static void Test()
        {
            var head = AssortedMethods.randomLinkedList(5, 1, 20);
            Console.WriteLine("Original=" + head.printForward());
            head = Reverse(head);
            Console.WriteLine("Reversed=" + head.printForward());
            
            var head2 = AssortedMethods.randomLinkedList(5, 1, 20);
            head2 = ReverseDDL(head2);
        }

        public static LinkedListNode Reverse(LinkedListNode node)
        {
            LinkedListNode previous = null;
            while (node != null)
            {
                LinkedListNode temp = node.next;
                node.next = previous;
                previous = node;
                node = temp;
            }

            return previous;
        }

        public static LinkedListNode ReverseDDL(LinkedListNode node)
        {
            LinkedListNode previous = null;
            while (node != null)
            {
                LinkedListNode temp = node.next;
                node.next = previous;
                node.prev = temp;
                previous = node;
                node = temp;
            }

            return previous;
        }
    }
}
