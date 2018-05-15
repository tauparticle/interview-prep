using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.StringProblems
{
    public static class TransformWordIntoOtherWord
    {
        public static void Test()
        {
            String[] words = { "maps", "tan", "tree", "apple", "cans", "help", "aped", "free", "apes", "flat", "trap", "fret", "trip", "trie", "frat", "fril" };
            HashSet<string> dict = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
            foreach (string w in words)
            {
                dict.Add(w.ToUpper());
            }
            LinkedList<String> list = transform("tree", "flat", dict);
            foreach (String word in list)
            {
                Console.WriteLine(word + "->");
            }
        }


        /// <summary>
        ///  Given a start and end word and a dictionary, return a list of one edit words that transforms between start and end 
        /// </summary>
        /// <remarks> n = length of the start word and m be the number of like-sized words in the dictionary.  The runtime
        /// of this algorithm is O(nm) since the while loop will dequeue at most m unique words.  The for loop is O(n) since it walks 
        /// down the string applying a fixed number of replacements to each one.
        /// </remarks>
        public static LinkedList<string> transform(string startWord, string stopWord, HashSet<string> dictionary)
        {
            if (startWord == null || stopWord == null) return null;
            if (startWord.Length != stopWord.Length) throw new ArgumentException("startWord and endWord are not the same length");
            startWord = startWord.ToUpper();
            stopWord = stopWord.ToUpper();
            Queue<String> actionQueue = new Queue<String>();
            HashSet<String> visitedSet = new HashSet<String>();
            Dictionary<String, String> backtrackMap = new Dictionary<String, String>();

            actionQueue.Enqueue(startWord);
            visitedSet.Add(startWord);

            while (actionQueue.Count > 0)
            {
                String w = actionQueue.Dequeue();
                // For each possible word v from w with one edit operation
                foreach (String v in getOneEditWords(w))
                {
                    if (v.Equals(stopWord))
                    {
                        // Found our word!  Now, back track.
                        LinkedList<String> list = new LinkedList<String>();
                        // Append v to list
                        list.AddFirst(v);
                        while (w != null)
                        {
                            list.AddFirst(w);
                            if (backtrackMap.ContainsKey(w))
                            {
                                w = backtrackMap[w];
                            }
                            else
                            {
                                w = null;
                            }
                        }
                        return list;
                    }

                    // If v is a dictionary word
                    if (dictionary.Contains(v))
                    {
                        if (!visitedSet.Contains(v))
                        {
                            actionQueue.Enqueue(v);
                            visitedSet.Add(v); // mark visited
                            backtrackMap.Add(v, w);
                        }
                    }
                }
            }
            return null;
        }

        private static ISet<String> getOneEditWords(String word)
        {
            ISet<String> words = new HashSet<string>();
            // for every letter
            for (int i = 0; i < word.Length; i++)
            {
                char[] wordArray = word.ToCharArray();
                // change that letter to something else
                for (char c = 'A'; c <= 'Z'; c++)
                {
                    if (c != word[i])
                    {
                        wordArray[i] = c;
                        words.Add(new String(wordArray));
                    }
                }
            }
            return words;
        }
    }
}
