using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    public static class BinarySearch
    {
        public static int BSearch(int[] arr, int left, int right, int x)
        {
            if (left > right)
            {
                return -1;  // not found
            }

            int mid = (left + right) / 2;

            if (arr[mid] == x)
            {
                return mid;
            }
            else if (arr[mid] > x)
            {
                return BSearch(arr, left, mid-1, x);
            }
            else
            {
                return BSearch(arr, mid+1, right, x);
            }
        }

        public class Range
        {
            public int Start { get; set; }
            public int End { get; set; }
            public Range(int start, int end)
            {
                this.Start = start;
                this.End = end;
            }
            public Range()
            {
                this.Start = -1;
                this.End = -1;
            }
        }

        // Returns a range value that matches a number in a sorted array with many duplicates
        public static Range FindValueRange(int[] arr, int num)
        {            
            int index = BSearch(arr, 0, arr.Length - 1, num);
            if (index == -1) new Range(-1, -1);
            
            // o(n) solution would be to iterate out both ends to find the range.  Inefficient if many duplicates.  
            // just use binary search again to maintain O(log n)
            int start = index - 1;
            int end = index + 1;
            while (start >= 0)
            {
                index = BSearch(arr, 0, start, num);
                if (index != -1)
                {
                    start = index-1;
                }
                else
                {
                    // Done searching lower range
                    break;
                }
                
            }
            while (end < arr.Length)
            {
                index = BSearch(arr, end, arr.Length - 1, num);
                if (index != -1)
                {
                    end = index + 1;
                }
                else
                {
                    // done searching high range
                    break;
                }
            }

            return new Range(start+1, end-1);
        }

        public static void Test()
        {

            var arr = new int[] { 1, 2, 2, 4, 5, 6, 7, 8 };
            Console.WriteLine("find 1 = " + FindValueRange(arr, 2));

            arr = new int[] { 1, 2, 3, 4, 4, 4, 4, 4 };
            Console.WriteLine("find 2 = " + FindValueRange(arr, 4));

            arr = new int[] { 1, 2, 3, 4, 5, 6, 7, 8 };
            Console.WriteLine("find 8 = " + FindValueRange(arr, 1));

            arr = new int[] { 1, 2, 3, 4, 5, 6, 7, 8 };
            Console.WriteLine("find 9 = " + FindValueRange(arr, 10));


        }
    }
}
