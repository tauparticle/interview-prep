/*
 
 Edit distance is a classic algorithm that is used in many applications, including Spell Correction, DNA Sequencing and Natural Language Processing. Given two Strings, a and b, write a method - editDistance that returns the minimum number of operations needed to transform a into b. The following character operations are allowed :
 
 a) Replace character
 b) Insert character
 c) Delete character
 
 Examples :
 
 editDistance("sale", "sales") => 1
 
 Operations :
 1) Insert "s"
 
 editDistance("sale", "sold") => 2
 
 Operations :
 1) Replace "a" with "o"
 2) Replace "e" with "d"
 
 editDistance("sa", "s") => 1
 
 Operations :
 1) Delete "a"
 
 
 1) Create a memo array to store the results of subproblems :
 int[][] memo = new int[lenA+1][lenB+1];
 
 2) Prefill the first cell with 0. Since we initialized memo with a primitive int, this will happen by default.
 
 3) Prefill the first row and column as such :
 for(int i = 1; i <= lenA; i++) memo[i][0] = i;
 
 for(int j = 1; j <= lenB; j++) memo[0][j] = j;
 
 These loops cover the single character insertion and deletion use case.
 
 4) Traverse across memo and fill the remaining cells with the following logic :
 
 a) If a.charAt(i) == b.charAt(j), no transformation is required and you can carry forward the value from memo[i-1][j-1];
 if(cA == cB){
 memo[i][j] = memo[i-1][j-1];
 }
 
 b) If the two chars are not the same, the value in the cell will be 1 + the minimum distance obtained by inserting, replacing or deleting a character. These three distances are already available in the cells to the left, top-left and top of the current cell, respectively. Store the minimum value in the current cell and proceed.
 
 if(cA == cB){
 memo[i][j] = memo[i-1][j-1];
 }
 else {
 int replaceDist = 1 + memo[i-1][j-1];
 int insertDist = 1 + memo[i][j-1];
 int deleteDist = 1 + memo[i-1][j];
 int minDist = Math.min(replaceDist,Math.min(insertDist, deleteDist));
 memo[i][j] = minDist;
 }
 
 5) Return the bottom right cell of memo.
 
 */

public int editDistance(String a, String b){
    int lenA = a.length(), lenB = b.length();
    int[][] memo = new int[lenA+1][lenB+1];
    // Prefill first row and column
    for(int i = 1; i <= lenA; i++) memo[i][0] = i;
    for(int j = 1; j <= lenB; j++) memo[0][j] = j;
    // Traverse and fill cells
    for(int i = 1; i <= lenA; i++){
        char cA = a.charAt(i-1);
        for(int j = 1; j <= lenB; j++){
            char cB = b.charAt(j-1);
            if(cA == cB){
                memo[i][j] = memo[i-1][j-1];
            }
            else {
                int replaceDist = 1 + memo[i-1][j-1];
                int insertDist = 1 + memo[i][j-1];
                int deleteDist = 1 + memo[i-1][j];
                int minDist = Math.min(replaceDist,Math.min(insertDist, deleteDist));
                memo[i][j] = minDist;
            }
        }
    }
    return memo[lenA][lenB];
}
