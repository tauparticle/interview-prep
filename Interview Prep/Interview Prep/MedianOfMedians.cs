using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    static class MedianOfMedians
    {

        /* Median of Medians for solving the median 
         * http://www.ics.uci.edu/~eppstein/161/960130.html
         *  select(L,k)
    {
    if (L has 10 or fewer elements)
    {
        sort L
        return the element in the kth position
    }

    partition L into subsets S[i] of five elements each
        (there will be n/5 subsets total).

    for (i = 1 to n/5) do
        x[i] = select(S[i],3)

    M = select({x[i]}, n/10)

    partition L into L1<M, L2=M, L3>M
    if (k <= length(L1))
        return select(L1,k)
    else if (k > length(L1)+length(L2))
        return select(L3,k-length(L1)-length(L2))
    else return M
    }
         * 
         * */

        public static int max(int[] array, int left, int right)
        {
            int max = int.MinValue;
            for (int i = left; i <= right; i++)
            {
                max = Math.Max(array[i], max);
            }
            return max;
        }

        public static int randomInt(int n)
        {
            Random rand = new Random();
            return (int)(rand.NextDouble() * n);
        }

        public static int randomIntInRange(int min, int max)
        {
            return randomInt(max + 1 - min) + min;
        }

        public static int partition(int[] array, int left, int right, int pivot)
        {
            while (true)
            {
                while (left <= right && array[left] <= pivot)
                {
                    left++;
                }

                while (left <= right && array[right] > pivot)
                {
                    right--;
                }

                if (left > right)
                {
                    return left - 1;
                }
                
                swap(array, left, right);
            }
        }

        public static void swap(int[] array, int i, int j)
        {
            int t = array[i];
            array[i] = array[j];
            array[j] = t;
        }

        /// <summary>
        /// Average case O(n) = n/2 + n/4 + n/8 .... = O(n)
        /// Worse case O(n^2) which occurs if we make poor pivot selections that doesn’t partition the array well, 
        /// and leaves most of the elements at one side and very few at the other.  Best solution is MedianOfMedians with worst case O(n)
        /// </summary>
        public static int QuickSelect(int[] array, int left, int right, int rank)
        {
            // pick a random pivot index.  
            int pivot = array[randomIntInRange(left, right)];
            
            // partition the elements around the value of the pivot value
            int leftEnd = partition(array, left, right, pivot); // returns end of left partition

            // need to know the size of the left side of the left partition
            int leftSize = leftEnd - left + 1;
            if (leftSize == rank + 1)
            {
                // the left partition is equal to the rank we're looking for.  Just return the max value from the left partition
                return max(array, left, leftEnd);
            }
            else if (rank < leftSize)
            {
                // the ranked value is in the left partition
                return QuickSelect(array, left, leftEnd, rank);
            }
            else
            {
                // the ranked value is in hte right partition.  Need to reset the rank value for the right partition
                return QuickSelect(array, leftEnd + 1, right, rank - leftSize);
            }
        }


        public static void TestMedianOfMedians()
        {
            Console.WriteLine("");
            for (int i = 0; i < 9; ++i)
            {
                int[] a = new int[10] { 9, 2, 6, 8, 1, 3, 4, 5, 0, 7 };
                int k = QuickSelect(a, 0, a.Length-1, i);
                Console.WriteLine(i + "th = " + k);
            };
        }
    }
}


 