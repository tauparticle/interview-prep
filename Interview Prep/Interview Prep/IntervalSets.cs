using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{

    public interface Intervals
    {

        /**
         * Adds an interval [from, to] into internal structure.
         */
        void addInterval(int from, int to);


        /**
         * Returns a total length covered by intervals.
         * If several intervals intersect, intersection should be counted only once.
         * Example:
         *
         * addInterval(3, 6)
         * addInterval(8, 9)
         * addInterval(1, 5)
         *
         * getTotalCoveredLength() -> 6
         * i.e. [1,5] and [3,6] intersect and give a total covered interval [1,6]
         * [1,6] and [8,9] don't intersect so total covered length is a sum for both intervals, that is 6.
         *
         *                   _________
         *                                               ___
         *     ____________
         *
         * 0  1    2    3    4    5   6   7    8    9    10
         *
         */
        int getTotalCoveredLength();
    }

    public class IntervalSets : Intervals
    {
        internal class Interval
        {
            internal int Start { get; set; }
            internal int End { get; set; }
            internal int Range { get { return this.End - this.Start; } }
        }

        private List<Interval> intervals = new List<Interval>();

        public void addInterval(int from, int to)
        {
            // O(n) where n = number of disjoint intervals
            if (to < from)
            {
                throw new ArgumentOutOfRangeException("to", "cannot be less than from");
            }

            // solution !!!!!!!!!!!!!!!!!!!!
            // find all intervals where new interval intersects the range.  Create a union of them all, and remove them from our interval list
            // can also track the largest range as we add, so we have an O(1) solution in the next 

            // note that extending interval rangs may overlap other intervals. Won't change the outcome, but we can optimize space further by collapsing these intervals
            foreach (Interval i in intervals)
            {
                // 1)  if new interval is witin the current interval, 
                // -> do nothing
                if (i.Start <= from && i.End >= to)
                {
                    return;
                }
                // 2)  if the interval start is less than a known interval, and ends within known interval
                // -> lower known interval start range to include the start
                if (from < i.Start && (to >= i.Start && to <= i.End))
                {
                    i.Start = from;
                    return;
                }

                // 3) if the interval start is within a known interval, and the end is past the known interval end
                // -> extend the known interval end
                if (from >= i.Start && from <= i.End && to > i.End)
                {
                    i.End = to;
                    return;
                }
            }


            // 4) The two intervals are disjoint, just add the new one to the list
            Interval interval = new Interval {Start = from, End = to};
            this.intervals.Add(interval);
        }

        public int getTotalCoveredLength()
        {
            // O(n) where n = number of disjoint intervals
            int maxLength = 0;
            // iterate through  known intervals and return the max range
            foreach (Interval i in this.intervals)
            {
                maxLength = Math.Max(maxLength, i.Range);
            }

            return maxLength;
        }
    }
}
