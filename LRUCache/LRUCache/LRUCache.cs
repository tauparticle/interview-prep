

namespace LRUCache
{
    using System;
    using System.Collections.Generic;
    using System.Text;
    using System.Runtime.CompilerServices;

    internal class LRUCacheItem<K, V>
    {
        public LRUCacheItem(K k, V v)
        {
            key = k;
            value = v;
        }
        public K key;
        public V value;
    }

    public class LRUCache<K, V>
    {

        private int capacity;
        private Dictionary<K, LinkedListNode<LRUCacheItem<K, V>>> cacheMap = new Dictionary<K, LinkedListNode<LRUCacheItem<K, V>>>();
        private LinkedList<LRUCacheItem<K, V>> lruList = new LinkedList<LRUCacheItem<K, V>>();
        private object locker = new object();

        public LRUCache(int capacity)
        {
            this.capacity = capacity;
        }

        public V get(K key)
        {
            lock (locker)
            {
                LinkedListNode<LRUCacheItem<K, V>> node;
                if (this.cacheMap.TryGetValue(key, out node))
                {
                    System.Console.WriteLine("Cache HIT " + key);
                    V value = node.Value.value;

                    this.lruList.Remove(node);
                    this.lruList.AddLast(node);
                    return value;
                }
            }
            System.Console.WriteLine("Cache MISS " + key);
            return default(V);
        }

        public void add(K key, V val)
        {
            lock (locker)
            {
                if (this.cacheMap.Count >= capacity)
                {
                    // Remove from LRUPriority
                    LinkedListNode<LRUCacheItem<K, V>> removeNode = this.lruList.First;
                    this.lruList.RemoveFirst();
                    // Remove from cache
                    this.cacheMap.Remove(removeNode.Value.key);
                }
                LRUCacheItem<K, V> cacheItem = new LRUCacheItem<K, V>(key, val);
                LinkedListNode<LRUCacheItem<K, V>> node = new LinkedListNode<LRUCacheItem<K, V>>(cacheItem);
                this.lruList.AddLast(node);
                this.cacheMap.Add(key, node);
            }
        }
    }
}