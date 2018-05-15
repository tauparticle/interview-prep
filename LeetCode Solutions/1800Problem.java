// java.util.* has been imported for this problem.
// You don't need any other imports.

public static  ArrayList<String> getStringsFromNums(String digits) 
{
      
       HashMap<Character, String> mapping = new HashMap<Character, String>();
        mapping.put('2', "abc");
        mapping.put('3', "def");
        mapping.put('4', "ghi");
        mapping.put('5', "jkl");
        mapping.put('6', "mno");
        mapping.put('7', "pqrs");
        mapping.put('8', "tuv");
        mapping.put('9', "wxyz");
        
        class PhoneNode
        {
            String word;
            int digitCount;
            PhoneNode(String w, int c)
            {
                word = w;
                digitCount = c;
            }
        }
        
        ArrayList<String> out = new ArrayList<String>();
        Stack<PhoneNode> stack = new Stack<PhoneNode>();
        int len = digits.length();
        
        for (Character c : mapping.get(digits.charAt(0)).toCharArray())
        {
            stack.push(new PhoneNode(String.valueOf(c), 1));
        }
             
        while (!stack.isEmpty())
        {
            PhoneNode node = stack.peek();
            stack.pop();
            
            if (node.digitCount == len)
            {
                out.add(node.word);
            }
            else
            {
                for (Character ch : mapping.get(digits.charAt(node.digitCount)).toCharArray())
                {
                    stack.push(new PhoneNode(node.word + ch, node.digitCount + 1));
                }
            }
        }
             
        return out;

}