using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.HardQuestions
{
    public static class FindMissingNumberInString
    {
        static bool ExpectedNextNum(string str, int num, int start)
        {
            if (start + num.ToString().Length > str.Length)
            {
                return false;
            }

            int expected;
            bool result = int.TryParse(str.Substring(start, num.ToString().Length), out expected);
            return result && (num == expected);
        }

        static int FindMissingNum(string str)
        {
            int len = str.Length;
            int i = 1;
            int missingNum = int.MinValue;

            while (i <= len / 2)
            {
                int start = i;
                int curr;
                bool result = int.TryParse(str.Substring(0, i), out curr);
                if (!result) break;

                while (result)
                {
                    if (result = ExpectedNextNum(str, curr + 1, start))
                    {
                        start += (curr + 1).ToString().Length;
                        curr = curr + 1;
                    }
                    else if (result = ExpectedNextNum(str, curr + 2, start))
                    {
                        start += (curr + 2).ToString().Length;
                        missingNum = curr + 1;
                        curr = curr + 2;
                    }
                }

                if (start == len)
                {
                    return missingNum;
                }

                i++;
            }

            return missingNum;
        }

        static void DoTest(string str)
        {
            Console.WriteLine("Input  : {0}", str);
            Console.WriteLine("Output : {0}", FindMissingNum(str));
            Console.WriteLine("--------------------------------");
        }

        public static void Test()
        {
            DoTest("0123456781011");// expect 9
            DoTest("012345678911"); // expect 10
            DoTest("911");          // expect 10
            DoTest("4142434546");   // expect 44
            DoTest("99101102103");  // expect 100
            DoTest("101112101114"); // expect 101113
        }
    }
}
