using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.DivideAndConquer
{
    public static class FindElementInRotatedArray
    {
        public static void Test()
        {
            int[] a = {2,2,2,3,4,9,10,0,1,1};
            Console.WriteLine();
            Console.WriteLine(BinarySearchRotated(a, 0, a.Length - 1, 0));
            Console.WriteLine(BinarySearchRotated(a, 0, a.Length - 1, 3));
            Console.WriteLine(BinarySearchRotated(a, 0, a.Length - 1, 4));
            Console.WriteLine(BinarySearchRotated(a, 0, a.Length - 1, 1));
            Console.WriteLine(BinarySearchRotated(a, 0, a.Length - 1, 9));
            Console.WriteLine(BinarySearchRotated(a, 0, a.Length - 1, 2));

            Console.WriteLine();
            Console.WriteLine(pivotedBinarySearch(a, 0));
            Console.WriteLine(pivotedBinarySearch(a, 3));
            Console.WriteLine(pivotedBinarySearch(a, 4));
            Console.WriteLine(pivotedBinarySearch(a, 1));
            Console.WriteLine(pivotedBinarySearch(a, 9));
            Console.WriteLine(pivotedBinarySearch(a, 2));
        }

        //Searches an element no in a pivoted sorted array arrp[] of size arr_size 
        public static int pivotedBinarySearch(int[] arr, int no)
        {
            int pivot = findPivot(arr, 0, arr.Length-1);

            // If we didn't find a pivot, then array is not rotated at all  
            if (pivot == -1)
                return binarySearch(arr, 0, arr.Length - 1, no);

            // If we found a pivot, then first compare with pivot and then
            // search in two subarrays around pivot
            if (arr[pivot] == no)
                return pivot;
            if (arr[0] <= no)
                return binarySearch(arr, 0, pivot - 1, no);
            else
                return binarySearch(arr, pivot + 1, arr.Length - 1, no);
        }

 
        //Function to get pivot. For array 3, 4, 5, 6, 1, 2 it will return 3. If array is not rotated at all, then it returns -1 */
        public static int findPivot(int[] arr, int low, int high)
        {
            // base cases
            if (high < low) return -1;
            if (high == low) return low;

            int mid = (low + high) / 2; 
            if (mid < high && arr[mid] > arr[mid + 1])
                return mid;
            if (mid > low && arr[mid] < arr[mid - 1])
                return (mid - 1);
            if (arr[low] >= arr[mid])
                return findPivot(arr, low, mid - 1);
            else
                return findPivot(arr, mid + 1, high);
        }


        // Standard Binary Search function
        public static int binarySearch(int[] arr, int low, int high, int no)
        {
            if (high < low)
                return -1;
            int mid = (low + high) / 2; /*low + (high - low)/2;*/
            if (no == arr[mid])
                return mid;
            if (no > arr[mid])
                return binarySearch(arr, (mid + 1), high, no);
            else
                return binarySearch(arr, low, (mid - 1), no);
        }



        //------------------------ solution from interview book ------------------------------
        public static int BinarySearchRotated(int[] a, int left, int right, int x)
        {
            if (right < left)
            {
                return -1;
            }

            int mid = (left + right) / 2;

            if (x == a[mid])
            {
                // Found element
                return mid;
            }


            /* While there may be an inflection point due to the rotation, either the left or 
             * right half must be normally ordered.  We can look at the normally ordered half
             * to make a determination as to which half we should search. 
             */
            if (a[left] < a[mid])
            {
                // Left is normally ordered.
                if (x >= a[left] && x <= a[mid])
                {
                    return BinarySearchRotated(a, left, mid - 1, x);
                }
                else
                {
                    return BinarySearchRotated(a, mid + 1, right, x);
                }
            }
            else if (a[mid] < a[right])//a[left])
            {
                // Right is normally ordered.
                if (x >= a[mid] && x <= a[right])
                {
                    return BinarySearchRotated(a, mid + 1, right, x);
                }
                else
                {
                    return BinarySearchRotated(a, left, mid - 1, x);
                }
            }
            else if (a[left] == a[mid])
            {
                // Left is either all repeats OR loops around (with the right half being all dups)
                if (a[mid] != a[right])
                {
                    // If right half is different, search there
                    return BinarySearchRotated(a, mid + 1, right, x);
                }
                else
                {
                    // Else, we have to search both halves
                    int result = BinarySearchRotated(a, left, mid - 1, x);
                    if (result == -1)
                    {
                        return BinarySearchRotated(a, mid + 1, right, x);
                    }
                    else
                    {
                        return result;
                    }
                }
            }
            return -1;

        }
    }
}
