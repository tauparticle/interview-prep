/*
 Given a two dimensional matrix made up of 0's and 1's, find the largest square containing all 1's and return its 'area'. The 'area' is simply the sum of all integers enclosed in the square.
 Example:
 
 Input Matrix :
 
 1101
 1101
 1111
 
 Output  : 4
 
 */

// o(nm) runtime
// o(nm) space complexity
public static int largestSquare(char[][] matrix) {
    
    int rows = matrix.length;
    int cols = matrix[0].length;
    
    int[][] memo = new int[rows][cols];
    for (int i=0; i<rows; ++i)
    {
        memo[i][0] = Character.getNumericValue(matrix[i][0]);   
    }
    
    for (int j=0; j<cols; ++j)
    {
        memo[0][j] = Character.getNumericValue(matrix[0][j]);   
    }
    
    for (int i=1; i<rows; ++i)
    {
        for (int j=1; j<cols; ++j)
        {
            if (matrix[i][j] == '1')
            {
                int min = Math.min(memo[i-1][j], memo[i-1][j-1]);
                min = Math.min(min, memo[i][j-1]);
                memo[i][j] = min + 1;
            }
            else 
            {
                memo[i][j] = 0;    
            }
        }
    }
    
    int max = 0;
    for (int i=0; i<rows; ++i)
    {
        for (int j=0; j<cols; ++j)
        {
            max = Math.max(max, memo[i][j]);
        }
    }
    return max * max;
}