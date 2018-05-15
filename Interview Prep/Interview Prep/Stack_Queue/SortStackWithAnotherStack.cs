using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.Stack_Queue
{
    public static class SortStackWithAnotherStack
    {
        public static void Test()
        {
            Stack<int> s = new Stack<int>();
            Random rand = new Random();
            Console.WriteLine("\nOriginal Stack");
            for (int i = 0; i < 10; ++i)
            {
                var v = rand.Next(0, 20);
                s.Push(v);
                Console.Write("{0}->", v);
            }

            var sortedS = sortStack(s);
            Console.WriteLine("\nSorted Stack");
            while (sortedS.Count > 0)
            {
                Console.Write("{0}->", sortedS.Pop());
            }
        }

        public static Stack<int> sortStack(Stack<int> s)
        {
            Stack<int> r = new Stack<int>();
            while (s.Count > 0)
            {
                int temp = s.Pop();
                while (r.Count > 0 && r.Peek() > temp)
                {
                    s.Push(r.Pop());
                }
                r.Push(temp);
            }

            return r;
        }
    }


}
