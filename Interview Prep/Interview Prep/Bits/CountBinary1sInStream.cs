using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.Bits
{
    using System.IO;

    public static class CountBinary1sInStream
    {
        public static void Test()
        {
            int a = 1234567890;
            Console.WriteLine("1s in {0} = {1}, binary={2}", a, Count1s(a), Convert.ToString(a, 2));
        }

        public static int Count1s(int num)
        {
            int oneCount = 0;
            while (num > 0)
            {
                if ((num & 1) == 1)
                {
                    ++oneCount;
                }
                num >>= 1;
            }
            return oneCount;
        }
    }
}
