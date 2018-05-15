/*
 Given an array of integers consisting of both positive and negative
 numbers, find the contiguous subsequence that has the maximum sum among all subsequences in the array (click the red text to learn more about subsequences). Write a method that takes in
 an array of integers arr and returns an array res containing 3 integers in the following format:
 
 res[0] = max sum
 res[1] = starting index of the subsequence
 res[2] = ending index of the subsequence
 
 
 Examples:
 
 maxContSequence({-1,-2,3,4,5}) ==> {12,2,4}
 
 maxContSequence({1,2,3,-2,5}) ==> {6,0,2}

 */

public static int[] maxContSequence(int[] arr) {

    int[] res = new int[3];

    if (arr == null || arr.length == 0)
    {
        res[0] = 0;
        res[1] = 0;
        res[2] = -1;
        return res;
    }
    
    int maxSum = arr[0];
    int maxSoFar = 0;
    int maxSoFarStart = 0;
    int maxSoFarEnd = 0;
    int maxStart = 0;
    int maxEnd = 0;
    
    // motified Kadane's algorithm
    for(int i=0; i<arr.length; ++i)
    {
        int sum = maxSoFar + arr[i];
        if (arr[i] > sum)
        {
            maxSoFar = arr[i];
            maxSoFarStart = i;
            maxSoFarEnd = i;
        }
        else
        {
            maxSoFar = sum;
            maxSoFarEnd = i;
        }
        
        if (maxSoFar > maxSum)
        {
            maxSum = maxSoFar;
            maxStart = maxSoFarStart;
            maxEnd = maxSoFarEnd;
        }
    }
    
    res[0] = maxSum;
    res[1] = maxStart;
    res[2] = maxEnd;
    return res;
}