using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    public static class RandomStringProblem
    {

        public static string compress(string str)
        {
            if (str.Length == 1) return str;

            StringBuilder sb = new StringBuilder();
            int index = 0;
            int i = 0;
            while (index < str.Length)
            {
                sb.Append(str[index]);
                for (i = index; i < str.Length && str[i] == str[index]; ++i)
                {
                    // noop
                }
                sb.Append(i - index);
                index = i;
            }

            return (sb.Length < str.Length) ? sb.ToString() : str;
        }

        // Write an algorithm such that if an element in a MxN matrix is 0, its entire row
        // and column is set to 0
        public static void setZeros(int[][] matrix)
        {
            int[] row = new int[matrix.Length];
            int[] col = new int[matrix[0].Length];

            for (int i = 0; i < matrix.Length; ++i)
            {
                for (int j = 0; j < matrix[0].Length; ++j)
                {
                    if (matrix[i][j] == 0)
                    {
                        row[i] = 1;
                        col[j] = 1;
                    }
                }
            }

            for (int i = 0; i < matrix.Length; ++i)
            {
                for (int j = 0; j < matrix[0].Length; ++j)
                {
                    if (row[i] == 1 || col[j] == 1)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        // Write a method to replace all spaces in a string with %20
        public static void EasyReplaceFun(ref char[] str, int length)
        {
            string s = new string(str);
            s = s.Replace(" ", "%20");
            str = s.ToArray();
        }
        public static void ReplaceFun(ref char[] str, int length)
        {
            if (str == null || str.Length == 0) return;
            int numOfSpaces = 0;
            foreach (char c in str)
            {
                if (c == ' ')
                {
                    ++numOfSpaces;
                }
            }

            if (numOfSpaces == 0) return;


            int newEnd = str.Length + numOfSpaces * 2;
            var newStr = new char[newEnd];
            newStr[--newEnd] = (char)0;
            for (int i = str.Length - 1; i >= 0; --i)
            {
                if (str[i] == ' ')
                {
                    newStr[newEnd--] = '0';
                    newStr[newEnd--] = '2';
                    newStr[newEnd--] = '%';
                }
                else
                {
                    newStr[newEnd--] = str[i];
                }
            }

            str = newStr;
        }

        // Write a method to decide if two strings are anagrams or not
        public static bool anagram(string s1, string s2)
        {
            int[] alpha = new int[256];
            int uniqueCharCount = 0;
            int charCount = s1.Length;

            if (s1 == null || s2 == null || s1.Length != s2.Length) return false;
            foreach (char c in s1)
            {
                if (alpha[c] == '\0')
                {
                    uniqueCharCount++;
                }
                alpha[c]++;
            }

            foreach (char c in s2)
            {
                if (alpha[c] > 0)
                {
                    alpha[c]--;
                    if (alpha[c] == 0)
                    {
                        uniqueCharCount--;
                    }
                }

                charCount--;
                if (uniqueCharCount == 0 && charCount > 0) return false;
            }

            return (uniqueCharCount == 0);
        }

        /// Question:  Remove duplicate characters from a string without creating any large
        /// data structures.
        public static string RemoveDuplicateCharacters(string str)
        {
            bool[] alpha = new bool[256];
            if (string.IsNullOrEmpty(str)) return str;

            StringBuilder sb = new StringBuilder();
            foreach (char c in str)
            {
                if (alpha[c])
                {
                    continue;
                }
                alpha[c] = true;
                sb.Append(c);
            }

            return sb.ToString();
        }

        public static string RemoveDuplicateCharacters(char[] str)
        {
            if (str == null || str.Length == 0) return string.Empty;
            bool[] alpha = new bool[256];

            alpha[str[0]] = true;
            int tail = 1;
            for (int i = 1; i < str.Length; ++i)
            {
                int c = str[i];
                if (alpha[c])
                {
                    continue;
                }
                str[tail++] = str[i];
                alpha[c] = true;
            }

            return new string(str, 0, tail);
        }

        /// <summary>
        /// Determine if string has unique characters
        /// </summary>
        /// <param name="s"></param>
        /// <returns></returns>
        public static bool isUniqueChars(string s)
        {
            bool[] alpha = new bool[256];
            if (string.IsNullOrEmpty(s)) return false;
            foreach (char c in s)
            {
                if (alpha[c]) return false;
                alpha[c] = true;
            }
            return true;
        }
    }
}
