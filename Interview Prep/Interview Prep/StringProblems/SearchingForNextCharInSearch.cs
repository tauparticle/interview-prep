using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.StringProblems
{
    
    /** 
* Return the smallest character that is strictly larger than the search character, 
* If no such character exists, return the smallest character in the array 
* @param sortedStr : sorted list of letters, sorted in ascending order. 
* @param c : character for which we are searching. 
* Given the following inputs we expect the corresponding output: 
* ['c', 'f', 'j', 'p', 'v'], 'a' => 'c' 
* ['c', 'f', 'j', 'p', 'v'], 'c' => 'f' 
* ['c', 'f', 'j', 'p', 'v'], 'p' => 'v' 
* ['c', 'f', 'j', 'p', 'v'], 'v' => 'c' // The wrap around case 
* ['c', 'f', 'k'], 'f' => 'k' 
* ['c', 'f', 'k'], 'c' => 'f' 
* ['c', 'f', 'k'], 'd' => 'f' 
*/
    public static class SearchingForNextCharInSearch
    {
        public static void Test()
        {
            Console.WriteLine("Search {0} should be {1}: actual {2}", 'a', 'c', FindSmallestStrictlyLarger(new char[] {'c', 'f', 'j', 'p', 'v'}, 'a'));
            Console.WriteLine("Search {0} should be {1}: actual {2}", 'c', 'f', FindSmallestStrictlyLarger(new char[] { 'c', 'f', 'j', 'p', 'v' }, 'c'));
            Console.WriteLine("Search {0} should be {1}: actual {2}", 'p', 'v', FindSmallestStrictlyLarger(new char[] { 'c', 'f', 'j', 'p', 'v' }, 'p'));
            Console.WriteLine("Search {0} should be {1}: actual {2}", 'v', 'c', FindSmallestStrictlyLarger(new char[] { 'c', 'f', 'j', 'p', 'v' }, 'v'));
            Console.WriteLine("Search {0} should be {1}: actual {2}", 'f', 'k', FindSmallestStrictlyLarger(new char[] { 'c', 'f', 'k' }, 'f'));
            Console.WriteLine("Search {0} should be {1}: actual {2}", 'c', 'f', FindSmallestStrictlyLarger(new char[] { 'c', 'f', 'k' }, 'c'));
            Console.WriteLine("Search {0} should be {1}: actual {2}", 'd', 'f', FindSmallestStrictlyLarger(new char[] { 'c', 'f', 'k' }, 'd'));

        }

        public static char FindSmallestStrictlyLarger(char[] list, char s)
        {
            if (list == null || list.Length == 0) throw new ArgumentNullException("list", "cannot be null or empty");

            int pos = BinarySearch(list, 0, list.Length - 1, s);
            if (pos == -1 || pos == list.Length-1)
            {
                return list[0];
            }

            return list[pos + 1];
        }

        public static int BinarySearch(char[] list, int left, int right, char x)
        {
            if (left > right) return -1;

            int mid = (left + right) / 2;
            if (list[mid] == x)
            {
                return mid;
            }

            if (list[mid] < x)
            {
                return BinarySearch(list, mid + 1, right, x);
            }
            else
            {
                return BinarySearch(list, left, mid - 1, x);
            }
        }
    }
}
