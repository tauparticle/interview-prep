// java.util.* has been imported for this problem.
// You don't need any other imports.

/*Given an array of integers, determine if it is possible to split
the array into two parts such that the sum of all elements in each part is the same.

Examples:

splitArray({1,2,3,4}) ==> true
splitArray({1,2,4}) ==> false

*/

public static boolean splitArray(int[] arr) {
    
    if (arr == null || arr.length == 0) return false;
    int sum = 0;
    for (int i=0; i<arr.length; ++i)
    {
        sum += arr[i];
    }
    
    if ((sum % 2) != 0)
    {
        // sum is odd.  Cannot split
        return false;
    }
    // see if combination of array values can sum to sum/2
    return CanSumToValue(arr, 0, sum / 2);
}

// here's another idea.  Instead of this, use combinaronics.  Same O(2^n), but O(1) space.

private static boolean CanSumToValue(int[] arr, int start_index, int target)
{
    if (start_index >= arr.length)
    {
        return (target == 0);
    }
    
    // Need to consider using current value AND not using the current value. 
    // O(2^n) though...look for a more efficient way
    if (CanSumToValue(arr, start_index + 1, target - arr[start_index]))
    {
        return true;
    }
    if (CanSumToValue(arr, start_index + 1, target))
    {
        return true;
    }
    return false;
}