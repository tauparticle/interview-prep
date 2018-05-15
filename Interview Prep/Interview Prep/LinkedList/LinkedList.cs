using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    static class LinkedListProblems
    {
        // Write code to remove duplicates from an unsorted linked list.
        // Followup:  How would you solve this problem if a temp buffer is not allowed?
        public static void deleteDups(LinkedListNode n)
        {
            HashSet<int> uniqueValue = new HashSet<int>();
            LinkedListNode previous = null;
            while (n != null)
            {
                if (uniqueValue.Contains(n.data))
                {
                    previous.next = n.next;
                    if (n.next != null) n.next.prev = previous;
                }
                else
                {
                    uniqueValue.Add(n.data);
                    previous = n;                    
                }
                n = n.next;
            }

        }
    }


    public class LinkedListNode
    {
        public LinkedListNode next;
        public LinkedListNode prev;
        public int data;

        public LinkedListNode(int d, LinkedListNode p, LinkedListNode n)
        {
            this.data = d;
            this.setNext(n);
            this.setPrevious(p);
        }
        public void setNext(LinkedListNode n)
        {
            next = n;
            if (n != null && n.prev != this)
            {
                n.setPrevious(this);
            }
        }

        public void setPrevious(LinkedListNode p)
        {
            prev = p;
            if (p != null && p.next != this)
            {
                p.setNext(this);
            }
        }

        public String printForward()
        {
            if (next != null)
            {
                return data + "->" + next.printForward();
            }
            else
            {
                return data.ToString();
            }
        }
    }

    public class AssortedMethods
    {
        public static LinkedListNode randomLinkedList(int N, int min, int max)
        {
            Random rand = new Random();
            LinkedListNode root = new LinkedListNode(randomIntInRange(min, max), null, null);
            LinkedListNode prev = root;
            for (int i = 1; i < N; i++)
            {
                int data = rand.Next(min, max);
                LinkedListNode next = new LinkedListNode(data, null, null);
                prev.setNext(next);
                prev = next;
            }
            return root;
        }

        public static int randomIntInRange(int min, int max)
        {
            Random rand = new Random();
            return rand.Next(min, max);
        }
    }


}
