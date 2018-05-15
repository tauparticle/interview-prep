/*
 
 Given an m x n matrix filled with non-negative integers, find the minimum sum along a path from the top-left of the grid to the bottom-right which minimizes the sum of all numbers along it. Return this minimum sum. The direction of movement is limited to right and down.
 Example:
 
 Input Matrix :
 
 1 2 3
 4 5 6
 7 8 9
 
 Output  : 21
 
 */

// java.util.* has been imported for this problem.
// You don't need any other imports.

// Runtime O(nm) -> Best DP solution
// Space O(nm)

public static int minWeightedPath(int[][] grid) {
          
    int rows = grid.length;
    int cols = grid[0].length;
    int[][] memo = new int[rows][cols];
    
    memo[0][0] = grid[0][0];
    
    for (int row = 1; row < rows; ++row)
    {
        memo[row][0] = memo[row-1][0] + grid[row][0];
    }
    
    for (int col = 1; col < cols; ++col)
    {
        memo[0][col] = memo[0][col-1] + grid[0][col];
    }
    
    for (int row = 1; row < rows; ++row)
    {
        for (int col = 1; col < cols; ++col)
        {
            int min = Math.min(memo[row-1][col], memo[row][col-1]);
            memo[row][col] = grid[row][col] + min;
        }
    }

    return memo[rows-1][cols-1];
}