using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.OOD
{
    public static class HashMapTester
    {
        public static void Test()
        {
            HashMap<string, int> hm = new HashMap<string, int>(10);
            hm.put("abc", 1);
            hm.put("def", 2);
            hm.put("ghi", 3);
            hm.put("jkw", 4);
            hm.put("the answer is", 42);
            Console.WriteLine(hm.get("abc"));
            Console.WriteLine(hm.get("def"));
            Console.WriteLine(hm.get("ghi"));
            Console.WriteLine(hm.get("jkw"));
            Console.WriteLine(hm.get("the answer is"));
        }
    }
    public class HashMap<K,V>
    {
        private List<KeyValuePair<K,V>>[] items;
        
        public HashMap(int size)
        {
            this.items = new List<KeyValuePair<K,V>>[size];
        }

        // really dumb hash code
        private int hashCode(K val)
        {
            return val.ToString().Length % items.Length;
        }

        public void put(K key, V value)
        {
            int x = this.hashCode(key);
            if (this.items[x] == null)
            {
                this.items[x] = new List<KeyValuePair<K, V>>();
            }

            // look for items with the same key and replace if found
            List<KeyValuePair<K, V>> collisions = this.items[x];
            foreach (KeyValuePair<K, V> kvp in collisions)
            {
                if (kvp.Key.Equals(key))
                {
                    collisions.Remove(kvp);
                    break;
                }
            }

            KeyValuePair<K,V> newElement = new KeyValuePair<K, V>(key, value);
            collisions.Add(newElement);
        }

        public V get(K key)
        {
            int x = this.hashCode(key);
            if (this.items[x] == null)
            {
                return default(V);
            }


            List<KeyValuePair<K, V>> collisions = this.items[x];
            foreach (KeyValuePair<K, V> kvp in collisions)
            {
                if (kvp.Key.Equals(key))
                {
                    return kvp.Value;
                }
            }

            return default(V);
        }
    }
}
