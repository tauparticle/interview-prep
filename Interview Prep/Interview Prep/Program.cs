using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Interview_Prep
{
    using Interview_Prep.Bits;
    using Interview_Prep.DataStructures;
    using Interview_Prep.DivideAndConquer;
    using Interview_Prep.DynamicProgramming;
    using Interview_Prep.Graph;
    using Interview_Prep.HardQuestions;
    using Interview_Prep.LinkedList;
    using Interview_Prep.OOD;
    using Interview_Prep.Stack_Queue;
    using Interview_Prep.StringProblems;
    using Interview_Prep.Trees;

    class Program
    {
        /// <summary>
        ///  interview questions for string problems
        /// </summary>
        /// <param name="args"></param>
        static void Main(string[] args)
        {
            String[] words = { "abcde", "hello", "apple", "kite", "padle" };
            foreach (string w in words)
            {
                Console.WriteLine(w + " : " + RandomStringProblem.isUniqueChars(w));
            }

            String s = "helloiloveyou";
            Console.WriteLine(s + " -> " + RandomStringProblem.RemoveDuplicateCharacters(s));
            Console.WriteLine(s + " -> " + RandomStringProblem.RemoveDuplicateCharacters(s.ToCharArray()));

            Console.WriteLine("apple, papel : " + RandomStringProblem.anagram("apple", "papel"));
            Console.WriteLine("carrot, tarroc : " + RandomStringProblem.anagram("carrot", "tarroc"));
            Console.WriteLine("hello, llloh : " + RandomStringProblem.anagram("hello", "llloh"));

            s = "A quick brown fox jumped over the log";
            var sarr = s.ToArray();
            var saar2 = s.ToArray();
            RandomStringProblem.ReplaceFun(ref sarr, sarr.Length);
            RandomStringProblem.ReplaceFun(ref saar2, sarr.Length);
            Console.WriteLine(string.Concat(sarr));
            Console.WriteLine(string.Concat(saar2));

            Console.WriteLine("aabcccaa => " + RandomStringProblem.compress("aabcccaa"));
            Console.WriteLine("aaaaaaab => " + RandomStringProblem.compress("aaaaaaab"));
            Console.WriteLine("ababababab => " + RandomStringProblem.compress("ababababab"));
            Console.WriteLine("avfffff => " + RandomStringProblem.compress("avfffff"));

            FindFirstNonRepeatingChar.Test();

            /// Linked List Problems

            LinkedListNode head = AssortedMethods.randomLinkedList(10, 0, 3);
            Console.WriteLine(head.printForward());
            LinkedListProblems.deleteDups(head);
            Console.WriteLine(head.printForward());

            // wordbreak problems
            TestWordBreak.Run();

            //MedianOfMedians.TestMedianOfMedians();

            LongestCommonSubsequence.Test();
           
            SumOfMaxRunningSequence.Test();

            TestRankNode.Test();

            NextInorderSuccessor.Test();

            CircularArrayTest.Test();

            LongestPalindrome.Test();

            IsomorphicStrings.Test();

            FindMinAbsFrom2Arrays.Test();

            ValidateIsBST.Test();

            CoinPuzzle.Test();

            BinarySearch.Test();

            RansomNote.Test();

            atoi.Test();

            TrieTest.Test();

            IsTreeBalanced.Test();

            //TestProducerConsumer.Test();

            ShuffleDeck.Test();

            //QuickRankSearch.Test();

            ParenthesisCombo.Test();

            Permutations.Test();

            Combinations.Test();

            CompressString.Test();

            BuildTreeFromMatrixInput.Test();

            FindAllRepeatingSubstrings.Test();

            PrintTreePaths.Test();

            FindLowestCommonAncestor.Test();

		    PrintLevelsOfABinaryTree.Test();

            FindPathBetween2NodesInTree.Test();

            FindPathExistsInGraph.Test();

            FindPathBetween2GraphNodes.Test();

            // RealTimeCounterTest.Test();

            DistanceBetweenWordsInASentence.Test();

            SearchingForNextCharInSearch.Test();

            HashMapTester.Test();

            FindElementInRotatedArray.Test();

            SubTrees.Test();

            LongestCommonSubstring.Test();

            LongestIncreasingSequenceQuestion.Test();

            ConvertTreeIntoDoublyLinkedList.Test();

            Count2sBetween0andN.Test();

            TestSuffixTrees.Test();
            
            TransformWordIntoOtherWord.Test();

            IsNumberAPalindrome.Test();

            ConvertNumberToPhrase.Test();

            CountBinary1sInStream.Test();

            ReverseBitsInUnsignedInt.Test();

            ReverseLinkedList.Test();
            
            DeleteDups.Test();

            _3SUM.Test();

            ArraySequencesThatAddUpToSum.Tests();

            FindBSTNodesThatSumUpToValue.Test();

            LengthOfLongestSubstringProblem.Test();

            //BuildTreeFromInorderAndPreorderTraversal.Test();

            ConvertTreeToDLL.Test();

            FindMissingNumberInString.Test();

            SortStackWithAnotherStack.Test();

            QueueFrom2Stacks.Test();

            Sort2Queues.Test();

            ConvertRomanNumeralToInt.Test();

            MergeAllLists.Test();

            DivideWithoutSlash.Test();

            //RegularExpression.Test();

            IsNumberValid.Test();

            Console.ReadKey();
            
        }
    }
}
