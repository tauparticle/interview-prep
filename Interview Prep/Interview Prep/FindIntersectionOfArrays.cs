using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    public static class FindIntersectionOfArrays
    {
        /// <summary>
        /// Returns the common elements between 2 sorted arrays.
        /// Runtime O(n + m) worst case if sizes are equal.  O(n) or O(m) whichever is smaller otherwise
        /// Space is O(n + m) worse case if array are equal and values unique
        /// </summary>
        public static IEnumerable<int> FindIntersectionOf2Arrays(int[] arr1, int[] arr2)
        {
            if (arr1 == null) throw new ArgumentNullException("arr1");
            if (arr2 == null) throw new ArgumentNullException("arr2");

            List<int> intersection = new List<int>();
            int i = arr1.Length - 1;
            int j = arr2.Length - 1;

            while (i >= 0 && j >= 0)
            {
                if (arr1[i] > arr2[j])
                {
                    i--;
                }
                else if (arr1[i] < arr2[j])
                {
                    j--;
                }
                else
                {
                    intersection.Add(arr1[i]);
                    i--;
                    j--;
                }
            }

            return intersection;
        }
    }
}
