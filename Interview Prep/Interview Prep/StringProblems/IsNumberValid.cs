using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.StringProblems
{
    public static class IsNumberValid
    {
        public static void Test()
        {
            Console.WriteLine("123456 = " + IsNumber("123456"));
            Console.WriteLine("+12.12 = " + IsNumber("+12.12"));
            Console.WriteLine("-.123 = " + IsNumber("-.123"));
            Console.WriteLine("  1.45.00 = " + IsNumber("  1.45.00"));
            Console.WriteLine(" +.1245   = " + IsNumber(" +.1245  "));
            Console.WriteLine(". 1245= " + IsNumber(". 1245"));
        }

        public static bool IsNumber(string number)
        {
            if (string.IsNullOrEmpty(number)) return false;

            int index = 0;
            while (index < number.Length && number[index] == ' ')
            {
                index++;
            }

            if (index < number.Length && (number[index] == '+' || number[index] == '-'))
            {
                index++;
            }

            while (index < number.Length && char.IsDigit(number, index))
            {
                index++;
            }

            if (index < number.Length && number[index] == '.')
            {
                index++;
                // check all chars right of . to make sure they are digits as well
                while (index < number.Length && char.IsDigit(number, index)) index++;    
  
            }

            // advance as long as we have just spaces
            while (index < number.Length && number[index] == ' ')
            {
                index++;
            }

            // return true iff we're at the end of the string
            return index == number.Length;
        }
    }
}
