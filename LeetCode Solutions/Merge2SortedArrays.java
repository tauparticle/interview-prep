// Given two sorted integer arrays A and B, merge B into A as one sorted array.
// Note:
// You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. 
// The number of elements initialized in A and B are m and n respectively.

public class Solution {
    public void merge(int A[], int m, int B[], int n) {
        int a=m-1;
        int b=n-1;
        int i=m+n-1;    // calculate the index of the last element of the merged array

        // go from the back by A and B and compare and but to the A element which is larger
        while(a>=0 && b>=0) {
            if(A[a]>B[b])   A[i--]=A[a--];
            else            A[i--]=B[b--];
        }

        // if B is longer than A just copy the rest of B to A location, otherwise no need to do anything
        while(b>=0)         A[i--]=B[b--];
    }
}