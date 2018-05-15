using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    using System.Diagnostics;
    using System.Threading;

    public static class RealTimeCounterTest
    {
        public static void Test()
        {
            RealTimeCounter2 rtc = new RealTimeCounter2();
            
            //rtc.Start();
            while (true)
            {
                rtc.increment();
                Console.WriteLine("second:{0}, min:{1}, hour:{2}, day:{3}", rtc.getCountInLastSecond(), rtc.getCountInLastMinute(), rtc.getCountInLastHour(), rtc.getCountInLastDay());
                Thread.Sleep(1000);
            }
        }
    }

    interface IRealTimeCounter
    {
        void increment();
        int getCountInLastSecond();
        int getCountInLastMinute();
        int getCountInLastHour();
        int getCountInLastDay();
    }

    public class RingBuffer
    {
        private int[] buffer;
        private int index = 0;
        public long LastSampleInsertionTime { get; private set; }

        public RingBuffer(int size)
        {
            this.buffer = new int[size];
            this.index = 0;
            this.LastSampleInsertionTime = 0;
        }

        public void AddSample(int sample, long now)
        {
            this.LastSampleInsertionTime = now;

            if (this.index == buffer.Length - 1)
            {
                this.index = 0;
            }

            this.buffer[this.index++] = sample;

        }

        public int GetCount()
        {
            int sum = 0;

            for (int i = 0; i < this.buffer.Length; ++i)
            {
                sum += this.buffer[i];
            }

            return sum;
        }
    }

    public class RealTimeCounter2 : IRealTimeCounter
    {
        private RingBuffer minuteSamples = new RingBuffer(60); // seconds per minute
        private RingBuffer hourSamples = new RingBuffer(60); // minutes per hour
        private RingBuffer daySamples = new RingBuffer(24); // hours per day

        private LinkedList<long> currentSamples = new LinkedList<long>();
        private List<long> prunedList = new List<long>();
        private Thread housekeepingThread;
        private bool running = false;
        private object locker = new object();

        public RealTimeCounter2()
        {
            this.housekeepingThread = new Thread(Housekeeping);
        }

        public void Start()
        {
            this.running = true;
            this.housekeepingThread.Start();
        }

        public void Stop()
        {
            this.running = false;
            this.housekeepingThread.Join();
        }

        private void Housekeeping()
        {
            while (this.running)
            {
                long now = Stopwatch.GetTimestamp();
                this.DoHousekeeping(now);
                Thread.Sleep(1000);
            }
        }

        private void DoHousekeeping(long now)
        {
            lock (this.locker)
            {
                // trim the tail off of the events per second
                this.pruneCurrentSamples(now);
                long span = now - this.minuteSamples.LastSampleInsertionTime;
                if (span >= TimeSpan.TicksPerSecond)
                {
                    this.minuteSamples.AddSample(this.currentSamples.Count + this.prunedList.Count, now);
                }

                span = now - this.hourSamples.LastSampleInsertionTime;
                if (span >= TimeSpan.TicksPerMinute)
                {
                    this.hourSamples.AddSample(this.minuteSamples.GetCount(), now);
                }

                span = now - this.daySamples.LastSampleInsertionTime;
                if (span >= TimeSpan.TicksPerHour)
                {
                    this.daySamples.AddSample(this.hourSamples.GetCount(), now);
                }
            }
        }

        public void increment()
        {
            long now = Stopwatch.GetTimestamp();

            lock (this.locker)
            {
                Console.WriteLine("incrementing hit cout");
                currentSamples.AddLast(now);
                this.pruneCurrentSamples(now);
            }
        }

        private void pruneCurrentSamples(long now)
        {
            long cuttoffTime = now - TimeSpan.TicksPerSecond;
            lock (this.locker)
            {
                while (this.currentSamples.Count > 0 && this.currentSamples.First.Value < cuttoffTime)
                {
                    Console.WriteLine("popping sample into pruned list");
                    this.prunedList.Add(this.currentSamples.First.Value);
                    this.currentSamples.RemoveFirst();
                }
            }
        }

        public int getCountInLastSecond()
        {
            lock (this.locker)
            {
                this.DoHousekeeping(Stopwatch.GetTimestamp());
                return this.currentSamples.Count;
            }
        }

        public int getCountInLastMinute()
        {
            lock (this.locker)
            {
                this.DoHousekeeping(Stopwatch.GetTimestamp());
                return this.minuteSamples.GetCount() + this.currentSamples.Count + this.prunedList.Count;
            }
        }

        public int getCountInLastHour()
        {
            lock (this.locker)
            {
                this.DoHousekeeping(Stopwatch.GetTimestamp());
                return this.hourSamples.GetCount() + this.minuteSamples.GetCount() +this.currentSamples.Count + this.prunedList.Count;
            }
        }

        public int getCountInLastDay()
        {
            lock (this.locker)
            {
                this.DoHousekeeping(Stopwatch.GetTimestamp());
                return this.daySamples.GetCount() + this.hourSamples.GetCount() + this.minuteSamples.GetCount() + this.currentSamples.Count + this.prunedList.Count;
            }
        }
    }

    public class RealTimeCounter : IRealTimeCounter
    {
        private long maxSamplesPerSecond = 1000;
        private List<long> listCounter;

        public RealTimeCounter()
        {
            listCounter = new List<long>();
        }

        public void increment()
        {
            if (listCounter.Count > TimeSpan.TicksPerDay * maxSamplesPerSecond)
            {
                cleanup(TimeSpan.TicksPerDay);
            }
            listCounter.Add(Stopwatch.GetTimestamp());
        }

        public int getCountInLastSecond()
        {
            return timeSince(Stopwatch.GetTimestamp(), TimeSpan.TicksPerSecond);
        }

        public int getCountInLastMinute()
        {
            return timeSince(Stopwatch.GetTimestamp(), TimeSpan.TicksPerMinute);
        }

        public int getCountInLastHour()
        {
            return timeSince(Stopwatch.GetTimestamp(), TimeSpan.TicksPerHour);
        }

        public int getCountInLastDay()
        {
            return timeSince(Stopwatch.GetTimestamp(), TimeSpan.TicksPerDay);
        }

        /**
          * This takes the current time and a timeframe
          * and returns the number of values in listCounter
          * that is larger than the now - timeframe.
          */

        private int timeSince(long now, long timeFrame)
        {
            if (listCounter.Count == 0) return 0;

            long currentTime = now - timeFrame;
            // Do binary search to find the insertion place
            // This is an O(log n) opertation
            int insertionPoint = listCounter.BinarySearch(currentTime);

            // If a value is not found with binary search
            // the insertion point is defined as (-(insertion point) - 1).
            if (insertionPoint >= 0)
            {
                // Exact match
                return listCounter.Count - insertionPoint;
            }
            else
            {
                return listCounter.Count + insertionPoint + 1;
            }
        }

        /**
          * Remove all items older than this timeframe.
          */

        private void cleanup(long timeFrame)
        {
            // Find all items older than a day an remove them
            long currentTime = Stopwatch.GetTimestamp() - timeFrame;
            int index = listCounter.BinarySearch(currentTime); // O (log n)
            index = (index >= 0) ? listCounter.Count - index : listCounter.Count + index + 1;
            listCounter.RemoveRange(0, listCounter.Count - index);
        }
    }
}
