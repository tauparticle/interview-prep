using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.HardQuestions
{
    public static class DivideWithoutSlash
    {
        public static void Test()
        {
            int a = 25;
            int b = 5;
            Console.WriteLine("{0} / {1} = {2}", a, b, binaryDivide(a, b));
            Console.WriteLine("{0} / {1} = {2}", a, b, divideByConquer(a, b, 0, a));
            a = 121;
            b = 7;
            Console.WriteLine("{0} / {1} = {2}", a, b, divideByConquer(a, b, 0, a));

        }



        private static int divideByConquer(int numerator, int demonimator, int min, int max)
        {
            int mid = (min + max) / 2;
            int value = mid * demonimator;
            int remainder = numerator - value;
            if (remainder >= 0 && remainder < demonimator)
            {
                return mid;
            }
            else if (remainder > demonimator)
            {
                return divideByConquer(numerator, demonimator, mid + 1, max);
            }
            else
            {
                return divideByConquer(numerator, demonimator, min, mid - 1);
            }
        }

        
        private static int binaryDivide(int dividend, int divisor)
        {
            int denom = divisor;
            int current = 1;
            int answer = 0;

            if (denom > dividend)
                return 0;

            if (denom == dividend)
                return 1;

            while (denom <= dividend)
            {
                denom <<= 1;
                current <<= 1;
            }

            denom >>= 1;
            current >>= 1;

            while (current != 0)
            {
                if (dividend >= denom)
                {
                    dividend -= denom;
                    answer |= current;
                }
                current >>= 1;
                denom >>= 1;
            }
            return answer;
           
        }

    }
}
