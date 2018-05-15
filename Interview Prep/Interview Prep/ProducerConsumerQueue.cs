using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    using System.Threading;

    public static class TestProducerConsumer
    {
        static ProducerConsumerQueue<int> pc = new ProducerConsumerQueue<int>(10);
        public static void Test()
        {
            
            Thread reader1 = new Thread(ReaderTask);
            Thread reader2 = new Thread(ReaderTask2);
            Thread writer1 = new Thread(WriterTask);
            Thread writer2 = new Thread(WriterTask2);

            reader1.Start(); reader2.Start(); writer1.Start(); writer2.Start();

            reader1.Join();
            reader2.Join();
            writer1.Join();
            writer2.Join();
        }

       
        public static void WriterTask()
        {
            for (int i = 0; i < 100; ++i)
            {
                Console.WriteLine("W1 writing " + i);
                pc.Produce(i);
                Thread.Sleep(100);
            }
        }

        public static void WriterTask2()
        {
            for (int i = 0; i < 100; ++i)
            {
                Console.WriteLine("W2 writing " + i);
                pc.Produce(i);
                Thread.Sleep(100);
            }
        }

        public static void ReaderTask()
        {
            for (int i = 0; i < 100; ++i)
            {
                int t = pc.Consume();
                Console.WriteLine("R1 Reading " + t);
                
                Thread.Sleep(200);
            }
        }

        public static void ReaderTask2()
        {
            for (int i = 0; i < 100; ++i)
            {
                int t = pc.Consume();
                Console.WriteLine("R2 Reading " + t);

                Thread.Sleep(200);
            }
        }
    }

    public class ProducerConsumerQueue<T>
    {
        private readonly Queue<T> itemQ;
        private readonly int maxSize;
        private readonly object locker = new object();

        public ProducerConsumerQueue(int size)
        {
            this.itemQ = new Queue<T>(size);
            this.maxSize = size;
        }

        public void Produce(T item)
        {
            lock (this.locker)
            {
                while (this.itemQ.Count >= this.maxSize)
                {
                    // wait for workers to drain
                    Console.WriteLine("Producer going to sleep");
                    Monitor.Wait(this.locker);
                }
                this.itemQ.Enqueue(item);
                Console.WriteLine("Producer enqueued job");
                Monitor.PulseAll(this.locker);
            }
        }

        public T Consume()
        {
            T item;
            lock (this.locker)
            {
                while (this.itemQ.Count == 0)
                {
                    Console.WriteLine("Consumer going to sleep");
                    Monitor.Wait(this.locker);
                }
                item = this.itemQ.Dequeue();
                Console.WriteLine("Consumer dequeueing a job");
                Monitor.PulseAll(this.locker);
            }

            return item;
        }
    }
}
