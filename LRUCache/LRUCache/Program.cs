using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LRUCache
{
    using System.Collections.Concurrent;
    using System.Collections.Specialized;

    class Program
    {
        static void Main(string[] args)
        {
            LRUCache<string, string> cache = new LRUCache<string, string>(10);
            for (int i = 0; i < 10; ++i)
            {
                cache.add(i.ToString(), i.ToString());
            }

            for (int i = 0; i < 10; ++i)
            {
                Console.WriteLine(cache.get(i.ToString()) + ",");
            }

            cache.add("100", "100");
            for (int i = 0; i < 10; ++i)
            {
                Console.WriteLine(cache.get(i.ToString()) + ",");
            }
            Console.ReadKey();
        }
    }
}
