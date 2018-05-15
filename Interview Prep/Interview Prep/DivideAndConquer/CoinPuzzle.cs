using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    public static class CoinPuzzle
    {
        // simulates a weight scale
        public static int weight(int[] arr, int leftStart, int leftEnd, int rightStart, int rightEnd)
        {
            //uint age = 1 << 5 | 5;
            int leftWeight = 0;
            int rightWeight = 0;

            while (leftStart <= leftEnd)
            {
                leftWeight += arr[leftStart++];
            }

            while (rightStart <= rightEnd)
            {
                rightWeight += arr[rightStart++];
            }

            if (leftWeight == rightWeight) return 0;
            if (leftWeight > rightWeight) return -1;
            else return 1;
        }

        // Find optimal way of finding the element in an array that is different in weight 
        public static int Search(int[] arr, int left, int right)
        {
            if (left > right)
            {
                return -1;
            }

            if (left == right)
            {
                return left;
            }

         
            int groupSize = (right - left) / 3;
            int leftEnd = left + groupSize;
            int rightStart = right - groupSize;

            switch (weight(arr, left, leftEnd, rightStart, right))
            {
                case 0:
                    return Search(arr, leftEnd + 1, rightStart - 1);
                case 1:
                    return Search(arr, left, leftEnd);
                case -1:
                    return Search(arr, rightStart, right);
                default:
                    throw new InvalidOperationException("invalid return type from weight");

            }

        }

        public static void Test()
        {
            int[] arr = new int[] { 1, 1, 1, 1, 1, 1, 1, 1 };
            Console.WriteLine("All same coins = " + Search(arr, 0, arr.Length-1));

            arr = new int[] { 0, 1, 1, 1, 1, 1, 1, 1 };
            Console.WriteLine("Should be 0 = " + Search(arr, 0, arr.Length-1));

            arr = new int[] { 1, 1, 1, 1, 1, 1, 1, 0 };
            Console.WriteLine("Should be 7 = " + Search(arr, 0, arr.Length-1));

            arr = new int[] { 1, 1, 1, 1, 1, 0, 1, 1 };
            Console.WriteLine("Should be 5 = " + Search(arr, 0, arr.Length-1));
        }

    }
}
