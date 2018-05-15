/*Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item. */

public class LRUCache {
    
    public class LinkedListNode {
	    public LinkedListNode next;
	    public LinkedListNode prev;
	    public int data;
	    public int key;
	    public LinkedListNode(int d, int k, LinkedListNode n, LinkedListNode p) {
	    	data = d;
	    	key = k;
	    	next = n;
	    	prev = p;
        }
    }
    
    private int maxSize;
    private HashMap<Integer, LRUCache.LinkedListNode> cacheMap = new HashMap<Integer, LRUCache.LinkedListNode>();
    LRUCache.LinkedListNode head;
    LRUCache.LinkedListNode tail;
    
    public LRUCache(int capacity) {
        this.maxSize = capacity;
        this.head = null;
        this.tail = null;
    }

    
    private void removeNodeFromLru(LRUCache.LinkedListNode node) {
        
        if (node.prev == null) {
            this.head = node.next;
        }
        else {
            node.prev.next = node.next;
        }
        
        if (node.next == null) {
            this.tail = node.prev;
        }
        else {
            node.next.prev = node.prev;
        }
    }
    
    private void AddToLruFront(LRUCache.LinkedListNode node) {
        if (this.head == null) {
            this.head = node;
            this.tail = node;
            node.prev = null;
            node.next = null;
        }
        else {
            this.insertBefore(this.head, node);
        }
    }
    
    private void insertBefore(LRUCache.LinkedListNode node, LRUCache.LinkedListNode newNode) {
        newNode.prev = node.prev;
        newNode.next = node;
        if (node.prev == null) {
            this.head = newNode;
        }
        else {
            node.prev.next = newNode;
        }
        
        node.prev = newNode;
    }
    
    
    public int get(int key) {
        
        if (!this.cacheMap.containsKey(key)) {
            return -1;
        }
        
        LRUCache.LinkedListNode node = this.cacheMap.get(key);
        this.removeNodeFromLru(node);
        this.AddToLruFront(node);
        return node.data;
    }
    
    public void set(int key, int value) {
    
        LRUCache.LinkedListNode node = null;
        if (this.cacheMap.containsKey(key)) {
            node = this.cacheMap.get(key);
            node.data = value;
            this.removeNodeFromLru(node);
        }
        else {
            node = new LRUCache.LinkedListNode(value, key, null, null);
        }
        
        this.cacheMap.put(key, node);
        this.AddToLruFront(node);
        
        // clean up cache if at max size
        if (this.cacheMap.size() > this.maxSize) {
            this.cacheMap.remove(this.tail.key);
            this.removeNodeFromLru(this.tail);
        }
    }
}