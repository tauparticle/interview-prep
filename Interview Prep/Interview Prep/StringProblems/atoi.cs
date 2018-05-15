using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    public static class atoi
    {
        public static void Test()
        {
            Console.WriteLine("123 = " + alphaToInt("123"));
            Console.WriteLine("-123 = " + alphaToInt("-123"));
            Console.WriteLine("+123 = " + alphaToInt("-123"));
            Console.WriteLine("1234567894545 = " + alphaToInt("1234567894545"));
            Console.WriteLine(" -1234567894545 = " + alphaToInt(" -1234567894545"));
            Console.WriteLine("9 = " + alphaToInt("9"));
            Console.WriteLine("9A1= " + alphaToInt("9A1"));

            Console.WriteLine("9.123 = " + alphaToFloat("9.123"));
            Console.WriteLine("+9.123 = " + alphaToFloat("+9.123"));
            Console.WriteLine("-9.123 = " + alphaToFloat("-9.123"));

            try
            {
                Console.WriteLine("-9.-123 = " + alphaToFloat("-9.12-3"));
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            string input = "-9498.13423345345";
            float output = alphaToFloat(input);
            Console.WriteLine("{0} = {1}", input, output);

           
            Console.WriteLine("123 = " + itoa(123));
            Console.WriteLine("-123 = " + itoa(-123));
            Console.WriteLine("123456789 = " + itoa(123456789));
            Console.WriteLine("9 = " + itoa(9));

            
        }

        const int CMaxNumber = 10;
        public static string itoa(int num)
        {
            bool isNeg = false;
            if (num < 0)
            {
                isNeg = true;
                num *= -1;
            }
            int index = 0;

            char[] number = new char[CMaxNumber];

            while (num > 0)
            {
                char val = (char)((num % 10) + '0');
                number[index++] = val;
                num /= 10;
            }

            --index;

            StringBuilder sb = new StringBuilder(CMaxNumber+1);
            if (isNeg)
            {
                sb.Append("-");
            }
            while (index >= 0)
            {
                sb.Append(number[index--]);
            }

            return sb.ToString();
        }

        public static int alphaToInt(string str)
        {   
            const int maxDiv10 = int.MaxValue / 10;

            int i=0;
            int n = str.Length;
            int sign = 1;
            while (i < n && str[i] == ' ') {
                i++;
            }
            if (i < n && str[i] == '+') {
                i++;
            }
            else if (i < n && str[i] == '-') {
                i++; 
                sign = -1;
            }

            int num = 0;
            while (i < n && char.IsDigit(str, i)) {
                int digit = str[i] - '0';
                if (num > maxDiv10) {
                    return sign == 1 ? int.MaxValue : int.MinValue;
                }
                num = num * 10 + digit;
                i++;
            }

            return num * sign;
        }


        private static long stringToFloat(string str, out long factor)
        {
            long number = 0;
            factor = 1;
            for (int i = str.Length - 1; i >= 0; i--)
            {
                long val = str[i] - '0';
                if (val < 0 || val > 9)
                {
                    throw new ArgumentException("malformed input");
                }
                val *= factor;
                factor *= 10;
                number += val;
            }

            return number;
        }

        public static float alphaToFloat(string str)
        {
            if (string.IsNullOrEmpty(str))
            {
                throw new ArgumentNullException("str");
            }

            long factor;
            bool isNeg = (str[0] == '-');
            bool isPos = (str[0] == '+'); 
            if (isNeg || isPos)
            {
                str = str.Substring(1);
            }

            if (str.Contains('.'))
            {
                string[] parts = str.Split(new char[]{'.'}, StringSplitOptions.RemoveEmptyEntries);
                if (parts.Length > 2)
                {
                    throw new ArgumentException("improper format");
                }
                else if (parts.Length == 2)
                {
                    float left = stringToFloat(parts[0], out factor);
                    float right = stringToFloat(parts[1], out factor);
                    right = right / factor;
                    float result = left + right;
                    return (isNeg) ? result * -1.0F : result;
                }
                else
                {
                    return isNeg ? -1.0F * stringToFloat(parts[0], out factor) : (float)stringToFloat(parts[0], out factor);
                }
            }

            return isNeg ? -1.0F * stringToFloat(str, out factor) : (float)stringToFloat(str, out factor);
        }
    }
}
