package ArrayAndStrings.MergeSortedArray;

public class MergeSortedArray {
	
	/*Given two sorted integer arrays A and B, merge B into A as one sorted array.
Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements 
initialized in A and B are m and n respectively.
	 */

	public void merge(int A[], int m, int B[], int n) {
        int j=m-1;
        int k=n-1;
        for(int i=n+m-1; i >= 0; i--) {
            if( k < 0) {
                break;
            }
            if(j<0)  {
                A[i] = B[k--];
            }
            else if(A[j] > B[k]) {
                A[i] = A[j--];
            }
            else {
                A[i] = B[k--];
                
            }
        }
    }
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
