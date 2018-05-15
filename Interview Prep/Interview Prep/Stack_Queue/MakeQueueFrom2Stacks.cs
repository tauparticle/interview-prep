using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.Stack_Queue
{
    public static class QueueFrom2Stacks
    {
        public static void Test()
        {
            MyQueue<int> q = new MyQueue<int>();
            for (int i = 0; i < 10; ++i)
            {
                Console.WriteLine("enqueue " + i);
                q.Enqueue(i);
            }

            Console.WriteLine("Dequeue : " + q.Dequeue());
            Console.WriteLine("Dequeue : " + q.Dequeue());
            Console.WriteLine("Dequeue : " + q.Dequeue());
            Console.WriteLine("Dequeue : " + q.Dequeue());
            Console.WriteLine("Dequeue : " + q.Dequeue());

            Console.WriteLine("Enqueue : 10");  q.Enqueue(10);
            Console.WriteLine("Enqueue : 11");  q.Enqueue(11);
            Console.WriteLine("Enqueue : 12");  q.Enqueue(12);

            while (q.Size() > 0)
            {
                 Console.WriteLine("Dequeue : " + q.Dequeue());
            }
        }
    }
        

    public class MyQueue<T>
    {
        private Stack<T> s1 = new Stack<T>();
        private Stack<T> s2 = new Stack<T>();

        public void Enqueue(T item)
        {
            this.s1.Push(item);
        }

        public int Size()
        {
            return s1.Count + s2.Count;
        }

        private void Rebalance()
        {
            if (s2.Count == 0)
            {
                while (s1.Count > 0)
                {
                    s2.Push(s1.Pop());
                }
            }
        }

        public T Dequeue()
        {
            this.Rebalance();
            return s2.Pop();
        }

        public T Peek()
        {
            this.Rebalance();
            return s2.Peek();
        }
    }
}
