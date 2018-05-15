/*
 Given a 'triangle' as an ArrayList of ArrayLists of integers, with each list representing a level of the triangle, find the minimum sum achieved by following a top-down path and adding the integer at each level along the path. Movement is restricted to adjacent numbers from the top to the bottom.
 
 Use a buffer array that is the length of the base of the triangle - int[] outBuffer = new int[input.get(height-1).size()];. Fill this buffer array with the last row of the triangle. Now, move up the triangle, and at each level, iterate across the level and add to the base buffer the minimum sum of the element directly above - outBuffer[i] = row.get(i) + Math.min(outBuffer[i], outBuffer[i+1]);. Finally, return the first element of the buffer - return outBuffer[0];
 
 */

// runtime O(n^2)
// space O(n)
public static int minTriangleDepth(ArrayList<ArrayList<Integer>> input) {
    int height = input.size();
    int[] outBuffer = new int[input.get(height-1).size()];
    
    for(int i = 0; i < input.get(height-1).size(); i++){
        outBuffer[i] = input.get(height-1).get(i);
    }
    
    for(int r = height-2; r >= 0; r--){
        ArrayList<Integer> row = input.get(r);
        for(int i = 0; i < row.size(); i++){
            outBuffer[i] = row.get(i) + Math.min(outBuffer[i], outBuffer[i+1]);
        }
    }
    return outBuffer[0];
}