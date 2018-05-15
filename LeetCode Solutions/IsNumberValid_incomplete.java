
/* 
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
*/

public class Solution {
    public boolean isNumber(String s) {
        
        if (s == null) {
            return false;
        }
        
        s = s.trim();
        
        if (s.length() == 0) {
            return false;
        }
        
        int index = 0;
        if (s.charAt(0) == '-' || s.charAt(0) == '+') {
            s = s.substring(1);
        }
        
        boolean seenDot = false;
        boolean seenE = false;
        
        for(; index < s.length(); ++index) {
            char c = s.charAt(index);
            
            if (!isAllowedNumericCharacter(c, seenE, seenDot)) {
                return false;
            }
            
            if (c == '.') {
                seenDot = true;
                if (!checkCharBeforeIndexIsInteger(index, s, seenE, seenDot, true)) {
                    return false;
                }
            }
            
            if (c == 'e') {
                seenE = true;
                if (!checkCharBeforeIndexIsInteger(index, s, seenE, seenDot, false)) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    private boolean checkCharBeforeIndexIsInteger(int index, String s, boolean seenE, boolean seenDot, boolean edgesOkay) {
        
        int len = s.length()-1;
        if (index == 0 && !edgesOkay) {
            return false;
        }
        
        if (index == len && !edgesOkay) {
            return false;
        }
        
        if (index == 0 && len == 0) {
            return false;
        }
        
        if (index == 0) {
             return isAllowedNumericCharacter(s.charAt(index+1), seenE, seenDot);
        } 
        else if (index == len) {
             return isAllowedNumericCharacter(s.charAt(index-1), seenE, seenDot);
        }
        else {
            return isAllowedNumericCharacter(s.charAt(index-1), seenE, seenDot) && 
                   isAllowedNumericCharacter(s.charAt(index+1), seenE, seenDot);
        }

    }
    
    private boolean isAllowedNumericCharacter(char c, boolean seenE, boolean seenDot) {
        switch (c) {
            case '.' : 
                return !seenDot;
            case 'e' : 
                return !seenE;
        }
        
        int i = c -  '0';
        if(i >= 0 && i <= 9) {
            return true;
        }
        
        return false;
    }
}