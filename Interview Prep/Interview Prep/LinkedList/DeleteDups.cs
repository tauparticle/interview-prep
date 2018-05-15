using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.LinkedList
{
    public static class DeleteDups
    {
        public static void Test()
        {
            var n = AssortedMethods.randomLinkedList(100, 0, 10);
            Console.WriteLine("Original = " + n.printForward());

            DeleteDuplicates(n);
            Console.WriteLine("deDuped = " + n.printForward());

            n = AssortedMethods.randomLinkedList(100, 0, 10);
            Console.WriteLine("Original = " + n.printForward());

            DeleteDupsNoMemory(n);
            Console.WriteLine("deDuped = " + n.printForward());
        }

        // O(N), but could be O(N) space if all duplicates
        public static void DeleteDuplicates(LinkedListNode n)
        {
            Dictionary<int, bool> dataMap = new Dictionary<int, bool>();

            LinkedListNode previous = null;
            while (n != null)
            {
                if (dataMap.ContainsKey(n.data))
                {
                    previous.next = n.next;
                }
                else
                {
                    dataMap.Add(n.data, true);
                    previous = n;
                }
                n = n.next;
            }
        }

        // O(n^2) runtime and O(1) space
        public static void DeleteDupsNoMemory(LinkedListNode head)
        {
            LinkedListNode current = head;
            while (current != null)
            {
                // remove all future nodes that have the same value
                LinkedListNode runner = current;
                while (runner.next != null)
                {
                    // skip over dup data
                    if (runner.next.data == current.data)
                    {
                        runner.next = runner.next.next;
                    }
                    else
                    {
                        runner = runner.next;
                    }
                }
                current = current.next;
            }

        }
    }
}
