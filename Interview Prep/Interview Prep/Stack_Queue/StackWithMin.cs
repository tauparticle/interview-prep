using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.Stack_Queue
{
    public class StackWithMin : Stack<int>
    {
        private Stack<int> s2;

        public StackWithMin()
        {
            this.s2 = new Stack<int>();
        }

        public int min()
        {
            if (s2.Count == 0)
            {
                return int.MinValue;
            }

            return s2.Peek();
        }

        public void push(int value)
        {
            if (value <= this.min())
            {
                s2.Push(value);
            }
            base.Push(value);
        }

        public int pop()
        {
            int value = base.Pop();
            if (value == this.min())
            {
                s2.Pop();
            }
            return value;
        }
    }
}
