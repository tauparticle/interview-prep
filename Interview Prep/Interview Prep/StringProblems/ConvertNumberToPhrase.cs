using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.StringProblems
{

    public static class ConvertNumberToPhrase
    {
        public static void Test()
        {
            
            Random rand = new Random();
            for (int i = 0; i < 5; ++i)
            {
                int number = rand.Next(0, 10);
                Console.WriteLine("{0} = {1}", number, NumberConverter.numToString(number));
            }

            for (int i = 0; i < 5; ++i)
            {
                int number = rand.Next(11, 20);
                Console.WriteLine("{0} = {1}", number, NumberConverter.numToString(number));
            }

            for (int i = 0; i < 5; ++i)
            {
                int number = rand.Next(100, 1000);
                Console.WriteLine("{0} = {1}", number, NumberConverter.numToString(number));
            }

            for (int i = 0; i < 5; ++i)
            {
                int number = rand.Next(10000, int.MaxValue);
                Console.WriteLine("{0} = {1}", number, NumberConverter.numToString(number));
            }
        }
    }

    public class NumberConverter
    {
        public static string[] digits = { "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
        public static string[] teens = { "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
        public static string[] tens = { "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
        public static string[] bigs = { "", "Thousand", "Million", "Billion", "Trillion"};

        public static String numToString(int number)
        {
            if (number == 0)
            {
                return "Zero";
            }

            if (number < 0)
            {
                return "Negative " + numToString(-1 * number);
            }
            int count = 0;
            String str = "";

            while (number > 0)
            {
                // for numbers greater than 1000, we need to just track the number of times 1000 goes into the number 
                // to see if we need to index into the "Thousand" or "Million" array bracket and just append this annotation to the
                // conversion of any number smaller than 1000
                if (number % 1000 != 0)
                {
                    str = numToString100(number % 1000) + bigs[count] + " " + str;
                }
                
                number /= 1000;
                count++;
            }

            return str;
        }

        // The best strategy here is to solve each number in 1-999 value passes.  
        public static string numToString100(int number)
        {
            string str = "";

            /* First Convert hundreds place */
            if (number >= 100)
            {
                str += digits[number / 100 - 1] + " Hundred ";
                number %= 100;
            }

            /* Next Convert tens place */
            if (number >= 11 && number <= 19)
            {
                // teens are a special case.  Just key in value and return
                return str + teens[number - 11] + " ";
            }
            else if (number == 10 || number >= 20)
            {
                // normal 10's range 10, 20-90
                str += tens[number / 10 - 1] + " ";
                number %= 10;
            }

            /* finally Convert ones place */
            if (number >= 1 && number <= 9)
            {
                str += digits[number - 1] + " ";
            }

            return str;
        }
    }
}
