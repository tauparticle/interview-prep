using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.HardQuestions
{
    public static class IsNumberAPalindrome
    {

        public static void Test()
        {
            int a = 12321;
            Console.WriteLine("Is num Palindrome {0} = {1}", a, IsPalindrome(a));
        }

        // best solution since reversing the string could lead to potential overflow, which is system-specific
        public static bool IsPalindrome(int x)
        {
            int div = 1;
            while (x / div >= 10)
            {
                div *= 10;
            }

            while (x != 0)
            {
                int l = x / div;
                int r = x % 10;
                if (l != r) return false;
                x = (x % div) / 10;
                div /= 100;
            }

            return true;
        }
    }
}
