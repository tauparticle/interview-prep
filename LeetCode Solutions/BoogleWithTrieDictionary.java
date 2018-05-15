/*You're given a 2D Boggle Board which contains an m x n matrix of chars - char[][] board, and a rudimentary, paper Dictionary in the form of an ArrayList of close to 10,000 words. Write a method - boggleByot that searches the Boggle Board for words in the dictionary. Your method should return an alphabetically sorted ArrayList of words that are present on the board as well as in the dictionary. Words on the board can be constructed with sequentially adjacent letters, where adjacent letters are horizontal or vertical neighbors (not diagonal). Also, each letter on the Boggle Board must be used only once. 
*/

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

// need to convert to trie dictionary first
public ArrayList<String> boggleByot(char[][] board, ArrayList<String> dictionary){
    
    TreeSet<String> foundWords = new TreeSet<String>();
    Trie dict = new Trie();
    for (String s : dictionary)
    {
        dict.insertWord(s);
    }
    
    int rows = board.length;
    int cols = board[0].length;
    
    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < cols; ++col)
        {
            mineForWords(board, row, col, "", dict, foundWords);
        }
    }
    
    return new ArrayList<String>(foundWords);
}

private void mineForWords(char[][] board, int row, int col, String current, Trie dict, TreeSet<String> foundWords)
{
    if (row < 0 ||
        row >= board.length ||
        col < 0 ||
        col >= board[0].length ||
        !dict.searchPrefix(current) ||
        board[row][col] == '*')
    {
        return;
    }
    
    char c = board[row][col];
    board[row][col] = '*';
    
    current += c;
    if (dict.searchWord(current))
    {
        foundWords.add(current);
    }
    
    mineForWords(board, row+1, col, current, dict, foundWords);
    mineForWords(board, row-1, col, current, dict, foundWords);
    mineForWords(board, row, col+1, current, dict, foundWords);
    mineForWords(board, row, col-1, current, dict, foundWords);
    
    board[row][col] = c;
    
}