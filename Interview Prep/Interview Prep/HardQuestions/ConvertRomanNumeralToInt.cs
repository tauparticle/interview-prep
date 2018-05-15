using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.HardQuestions
{
    public static class ConvertRomanNumeralToInt
    {
        public static void Test()
        {
            Console.WriteLine("CCXXXIV (should be 234)= " + RomanToInt("CCXXXIV"));
        }

        public static int RomanToInt(string roman)
        {
            int value = 0;
            int current = 0;
            roman = roman.ToLower();
            for (int i = roman.Length - 1; i >= 0; i--)
            {
                int digit = 0;
                switch (roman[i])
                {
                    case 'i':
                        digit = 1;
                        break;
                    case 'v':
                        digit = 5;
                        break;
                    case 'x':
                        digit = 10;
                        break;
                    case 'l':
                        digit = 50;
                        break;
                    case 'c':
                        digit = 100;
                        break;
                    case 'd':
                        digit = 500;
                        break;
                    case 'm':
                        digit = 1000;
                        break;
                }

                if (digit < current)
                {  // the stategy here is for IV (4), we want to subtract the I from the previous 5 to get 4.
                    current = digit * -1;
                }
                else
                {
                    current = digit;
                }
                value += current;
            }

            return value;
        }
    }
}
