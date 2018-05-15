class TrieNode {
    Character c;
    
    Boolean isLeaf = false;
    
    HashMap<Character, TrieNode> children = new HashMap<>();
    
    public TrieNode(){
    }
    
    public TrieNode(Character c)
    {
        this.c = c;
    }
}

class Trie {
    private TrieNode root;
    
    public Trie()
    {
        this.root = new TrieNode();
    }
    
    public void insertWord(String word)
    {
        TrieNode current = this.root;
        HashMap<Character, TrieNode> children = current.children;
        
        for (int i=0; i<word.length(); ++i)
        {
            char c = word.charAt(i);
            if (!children.containsKey(c))
            {
                children.put(c, new TrieNode(c));
            }
            current = children.get(c);
            children = current.children;
            
            if (i == word.length()-1)
            {
                current.isLeaf = true;
            }
        }
    }
    
    public Boolean searchWord(String word)
    {
        TrieNode current = this.root;
        HashMap<Character, TrieNode> children = current.children;
        
        for (int i=0; i<word.length(); ++i)
        {
            char c = word.charAt(i);
            if (!children.containsKey(c))
            {
                return false;
            }
            current = children.get(c);
            children = current.children;
        }
        
        return current.isLeaf;
    }
    
    public Boolean searchPrefix(String word)
    {
        TrieNode current = this.root;
        HashMap<Character, TrieNode> children = current.children;
        
        for (int i=0; i<word.length(); ++i)
        {
            char c = word.charAt(i);
            if (!children.containsKey(c))
            {
                return false;
            }
            current = children.get(c);
            children = current.children;
        }
        
        return true;
    }
}