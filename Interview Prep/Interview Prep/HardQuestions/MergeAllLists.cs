using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.HardQuestions
{
    public static class MergeAllLists
    {

        public static void Test()
        {
            List<List<int>> allLists = new List<List<int>>();

            List<int> a = new List<int>() { 1, 2, 3, 6, 8};
            List<int> b = new List<int>() { 2, 4, 7, 8, 90 };
            List<int> c = new List<int>() { 0, 4, 99 };

            PrintList(a); PrintList(b); PrintList(c);
            
            allLists.Add(a);
            allLists.Add(b);
            allLists.Add(c);

            var merged = MergeAllListsImpl(allLists);
            PrintList(merged);

            Console.WriteLine();

        }

        public static void PrintList(List<int> l)
        {
            Console.WriteLine("List");
            foreach (var n in l)
            {
                Console.Write("{0},", n);
            }

            Console.WriteLine();
        }


 


        public static List<int> MergeAllListsImpl(List<List<int>> allLists)
        {
            if (allLists == null) throw new ArgumentNullException("allLists");

            List<int> mergedList = new List<int>();
            List<int> listIndicies = new List<int>();
            int totalCount = 0;

            for (int i = 0; i < allLists.Count; ++i )
            {
                totalCount += allLists[i].Count;
                listIndicies.Insert(i, 0);
            }

            while (mergedList.Count < totalCount)
            {
                int minValue = int.MaxValue;
                int minIndex = 0;
                for (int i = 0; i < listIndicies.Count; ++i)
                {
                    if (listIndicies[i] == allLists[i].Count)
                    {
                        continue;
                    }
                    int value = allLists[i][listIndicies[i]];
                    if (value <= minValue)
                    {
                        minValue = value;
                        minIndex = i;
                    }
                }

                mergedList.Add(allLists[minIndex][listIndicies[minIndex]]);
                listIndicies[minIndex]++;
            }

            return mergedList;
        }
    }
}
