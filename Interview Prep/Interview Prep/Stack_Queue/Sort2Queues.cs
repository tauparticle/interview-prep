using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.Stack_Queue
{
    public static class Sort2Queues
    {
        public static void Test()
        {
            Queue<int> q1 = new Queue<int>();
            Queue<int> q2 = new Queue<int>();
            Random rand = new Random();
            Console.WriteLine("\nQueue1");
            for (int i = 0; i < 5; ++i)
            {
                var v = rand.Next(0, 20);
                q1.Enqueue(v);
                Console.Write("{0}->", v);
            }

            SortQueueUsingExtraQueue(q1);

            Console.WriteLine("\nSortedQ");
            while (q1.Count > 0)
            {
                Console.Write("{0}->", q1.Dequeue());
            }

        }


        /// <summary>
        /// function to sort a queue using an extra queue. 
        /// </summary>
        /// <param name="target">the target queue that contains all the unsorted elements</param>
        private static void SortQueueUsingExtraQueue(Queue<int> target)
        {
            if (target == null || target.Count < 2) return;

            var tmpQueue = new Queue<int>(); // the second Queue, this queue contains the sorted part of the target queue.
            var queueLength = target.Count; // length of the target queue. 
            var lastInput = target.Peek(); // element at the top of the "sorted" queue.
            var processedCount = 0; // currently processed item count. 
            bool sorted = false;

            while (!sorted)
            {
                // if the element element is lesser than the item on the top of the sorted queue, we move it from the target queue and push it into 
                // the sorted queue. 
                if (lastInput >= target.Peek())
                {
                    lastInput = target.Dequeue();
                    tmpQueue.Enqueue(lastInput);
                }

                // the poping element is bigger than the top element on the sorted queue, we put it back to the bottom of the queue and will process it later. 
                else
                {
                    target.Enqueue(target.Dequeue());
                }

                // continue if we still have item to process. 
                if (++processedCount != queueLength) continue;

                // once all item are processed, we check the length of the sorted queue, if the # of item equals the length of the orignal queue, means the 
                // sort is done. 
                if (tmpQueue.Count == queueLength)
                {
                    sorted = true;
                }

                // we dump all the elements to the target queue, if the sort is done, target queue ends up with all the element sorted, if not,
                // target queue ends with element that is parcially sorted.
                // We will process on until all the elements are sorted. 
                while (tmpQueue.Count > 0)
                {
                    target.Enqueue(tmpQueue.Dequeue());
                    lastInput = target.Peek(); // don't forget to reset lastInput.
                }

                processedCount = 0;
            }
        }
    }
}
