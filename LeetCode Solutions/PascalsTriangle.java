/*
 Given an input parameter numRows, generate the first numRows number of rows of Pascal's triangle. As a quick refresher - in a Pascal's triangle, each number is equal to the sum of the two directly above it.
 
 Example:
 
 Input  : 4
 Output :
 [
    [1],
   [1,1],
  [1,2,1],
 [1,3,3,1]
 
 ]
 */

// O(n^2) runtime and O(n^2) space
public static ArrayList<ArrayList<Integer>> generatePascalTriangle(int numRows) {
  
    ArrayList<ArrayList<Integer>> triangle = new ArrayList<ArrayList<Integer>>();
    if (numRows == 0) 
    {
        return triangle;
    }
    
    ArrayList<Integer> level = new ArrayList<Integer>();
    level.add(1);
    triangle.add(level);
    
    ArrayList<Integer> previous = null;
    
    for (int i=2; i<= numRows; ++i)
    {
        previous = level;
        level = new ArrayList<Integer>();
        level.add(1); // first
        
        for (int j=0; j < previous.size() - 1; ++j)
        {
            level.add(previous.get(j) + previous.get(j+1));
        }
        level.add(1); // last;
        triangle.add(level);
    }

    return triangle;


}