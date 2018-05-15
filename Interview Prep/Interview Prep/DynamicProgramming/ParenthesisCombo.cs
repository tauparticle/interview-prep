using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    public static class ParenthesisCombo
    {
        public static void Test()
        {
            GenerateBracketCombos(0);
            GenerateBracketCombos(1);
            GenerateBracketCombos(2);
            GenerateBracketCombos(3);
            GenerateBracketCombosOptimized(0);
            GenerateBracketCombosOptimized(1);
            GenerateBracketCombosOptimized(2);
            GenerateBracketCombosOptimized(3);

        }
        public static void GenerateBracketCombos(int number)
        {  
            PermutateBrackets(number, 0, 0, new char[number*2]);
        }

        public static void GenerateBracketCombosOptimized(int number)
        {
            PermutateBracketsOptimized(number, number, 0, new char[number * 2]);
        }
       
        // O(n) runtime due and O(2n) space
        private static void PermutateBrackets(int openGate, int closeGate, int index, char[] arr)
        {
            if (openGate == 0 && closeGate == 0)
            {
                Console.WriteLine(arr);
                return;
            }

            if (openGate > 0)
            {
                arr[index] = '(';
                PermutateBrackets(openGate - 1, closeGate + 1, index+1, arr);
            }
            if (closeGate > 0)
            {
                arr[index] = ')';
                PermutateBrackets(openGate, closeGate - 1, index+1, arr);
            }
        }

        public static void PermutateBracketsOptimized(int leftRem, int rightRem, int count, char[] arr)
        {
            if (leftRem < 0 || rightRem < leftRem) return;
            if (leftRem == 0 && rightRem == 0)
            {
                Console.WriteLine(arr);
            }
            else
            {
                if (leftRem > 0)
                {
                    arr[count] ='(';
                    PermutateBracketsOptimized(leftRem-1, rightRem, count+1, arr);
                }
                if (rightRem > leftRem)
                {
                    arr[count] = ')';
                    PermutateBracketsOptimized(leftRem, rightRem-1, count+1, arr);
                }
            }

        }
    }
}
