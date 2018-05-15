/*

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases. 

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome. 

Note:
 Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome. 
*/

// O(n) runtime, O(1) space
public class Solution {
    public boolean isPalindrome(String s) {
        
        int front = 0; 
        int back = s.length()-1;
        
        while (front < back)
        {
            while (front < back && !Character.isLetterOrDigit(s.charAt(front))) front++;
            while (front < back && !Character.isLetterOrDigit(s.charAt(back))) back--;
            if (Character.toLowerCase(s.charAt(front)) != Character.toLowerCase(s.charAt(back))) {
                return false;
            }
            
            front++; back--;
        }
        
        return true;
    }
}