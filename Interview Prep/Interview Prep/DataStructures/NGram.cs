using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.DataStructures
{
    public class Ngram
    {
        internal class result
        {
            internal String theWord;
            internal int theCount;

            public result(String w, int c)
            {
                theWord = w;
                theCount = c;
            }

            public void setTheCount(int c)
            {
                theCount = c;
            }

            public String getTheWord()
            {
                return theWord;
            }

            public int getTheCount()
            {
                return theCount;
            }
        }

        private List<result> results;

        public Ngram()
        {
            results = new List<result>();
        }
        public Ngram(String str, int n)
        {

        }

        public double getSimilarity(String wordOne, String wordTwo, int n)
        {
            List<result> res1 = processString(wordOne, n);
            //displayResult(res1);
            List<result> res2 = processString(wordTwo, n);
            //displayResult(res2);
            int c = common(res1, res2);
            int u = union(res1, res2);
            double sim = (double)c / (double)u;

            return sim;
        }

        private int common(List<result> One, List<result> Two)
        {
            int res = 0;

            for (int i = 0; i < One.Count; i++)
            {
                for (int j = 0; j < Two.Count; j++)
                {
                    if (One[i].theWord.Equals(Two[j].theWord))
                    {
                        res++;
                    }
                }
            }

            return res;
        }

        private int union(List<result> One, List<result> Two)
        {
            List<result> t = One;

            for (int i = 0; i < Two.Count; i++)
            {
                int pos = -1;
                bool found = false;
                for (int j = 0; j < t.Count && !found; j++)
                {
                    if (Two[i].theWord.Equals(t[j].theWord))
                    {
                        found = true;
                    }
                    pos = j;
                }

                if (!found)
                {
                    result r = Two[i];
                    t.Add(r);
                }
            }

            return t.Count;
        }

        private List<result> processString(String c, int n)
        {
            List<result> t = new List<result>();

            String spacer = "";
            for (int i = 0; i < n - 1; i++)
            {
                spacer = spacer + "%";
            }
            c = spacer + c + spacer;

            for (int i = 0; i < c.Count(); i++)
            {
                if (i <= (c.Count() - n))
                {
                    if (contains(c.Substring(i, n + i)) > 0)
                    {
                        t[i].setTheCount(results[i].getTheCount() + 1);
                    }
                    else
                    {
                        t.Add(new result(c.Substring(i, n + i), 1));
                    }
                }
            }
            return t;
        }

        private int contains(String c)
        {
            for (int i = 0; i < results.Count; i++)
            {
                if (results[i].theWord.Equals(c))
                    return i;
            }
            return 0;
        }

        private void displayResult(List<result> d)
    {
        for (int i = 0; i < d.Count; i++)
        {
            Console.WriteLine(d[i].theWord + " occurred " + d[i].theCount + " times");
        }
    }
    }
}
