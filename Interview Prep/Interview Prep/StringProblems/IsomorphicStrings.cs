using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    public static class IsomorphicStrings
    {
        public static bool IsIsomorphic(string a, string b)
        {
            if (a.Length != b.Length)
            {
                return false;
            }
            
            Dictionary<char, int> charMapA = new Dictionary<char, int>(256);
            Dictionary<char, int> charMapB = new Dictionary<char, int>(256);

            for (int i = 0; i < a.Length; ++i)
            {
                charMapA[a[i]] = i;
                charMapB[b[i]] = i;               
            }

            for (int i = 0; i < a.Length; ++i)
            {
                if (charMapA[a[i]] != charMapB[b[i]])
                {
                    return false;
                }
            }
            return true;
      
        }



        public static void Test()  
        {
            Console.WriteLine("Foo & Goo = " + IsIsomorphic("Foo", "Goo"));
            Console.WriteLine("foo & app = " + IsIsomorphic("foo", "app"));
            Console.WriteLine("bar & foo = " + IsIsomorphic("bar", "foo"));
            Console.WriteLine("turtle & tletur = " + IsIsomorphic("turtle", "tletur"));
            Console.WriteLine("ab & ca = " + IsIsomorphic("ab", "ca"));
            Console.WriteLine("ofo & app = " + IsIsomorphic("ofo", "app"));
        }
            
        

    }
}   
