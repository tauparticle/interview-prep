using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.Bits
{
    public static class ReverseBitsInUnsignedInt
    {
        public static void Test()
        {
            uint number = 123456;
            uint reverse = reverseXor(number);
            Console.WriteLine("{0} reversed = {1}", Convert.ToString(number, 2), Convert.ToString(reverse, 2));
        }

        // xor trick to swap bits in a number
        public static uint swapBits(uint x, int i, int j)
        {
            uint lo = ((x >> i) & 1);
            uint hi = ((x >> j) & 1);
            // first xor the bits to see if they're different.  If not, don't bother swapping
            if ((lo ^ hi) == 1)
            {
                // create a bitmask of 1s in the indicies we want to swap and xor this with the original.  
                // if the bits are different, they'll be toggled at both indicies.
                x ^= ((1U << i) | (1U << j));
            }
            return x;
        }

        // create front/end counters and swap bits at both indidcies
        public static uint reverseXor(uint x)
        {
            int n = sizeof(uint) * 8;
            for (int i = 0; i < n / 2; i++)
            {
                x = swapBits(x, i, n - i - 1);
            }
            return x;
        }
    }
}
