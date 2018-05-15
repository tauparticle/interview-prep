#include "StdAfx.h"
#include "StringUtil.h"
#include "string"
#include <vector>

StringUtil::StringUtil(void)
{
}


StringUtil::~StringUtil(void)
{
}

// Write an algorithm that will reverse a c style string
void StringUtil::reverseString(char * str)
{
	char * end = str;
	char temp;
	if (str != NULL) {
		while (*end != NULL) {
			++end;
		}
		--end;
		while (str < end) {
			temp = *str;
			*str++ = *end;
			*end-- = temp;
		}
	}
}

/* To make use of recursive calls, this function must return two things:
   1) Length of LIS ending with element arr[n-1]. We use max_ending_here 
      for this purpose
   2) Overall maximum as the LIS may end with an element before arr[n-1] 
      max_ref is used this purpose.
The value of LIS of full array of size n is stored in *max_ref which is our final result
*/
int StringUtil::doLongestIncreasingSequence( int arr[], int n, int *max_ref)
{
    /* Base case */
    if(n == 1)
        return 1;
 
    int res, max_ending_here = 1; // length of LIS ending with arr[n-1]
 
    /* Recursively get all LIS ending with arr[0], arr[1] ... ar[n-2]. If 
       arr[i-1] is smaller than arr[n-1], and max ending with arr[n-1] needs
       to be updated, then update it */
    for(int i = 1; i < n; i++)
    {
        res = doLongestIncreasingSequence(arr, i, max_ref);
        if (arr[i-1] < arr[n-1] && res + 1 > max_ending_here)
            max_ending_here = res + 1;
    }
 
    // Compare max_ending_here with the overall max. And update the
    // overall max if needed
    if (*max_ref < max_ending_here)
       *max_ref = max_ending_here;
 
    // Return length of LIS ending with arr[n-1]
    return max_ending_here;
}
 
// The wrapper function for _lis()
int StringUtil::LongestIncreasingSequence(int arr[], int n)
{
    // The max variable holds the result
    int max = 1;
 
    // The function _lis() stores its result in max
    doLongestIncreasingSequence( arr, n, &max );
 
    // returns max
    return max;
}

int StringUtil::longestIncreasingSequenceWithDp( int arr[], int n )
{
	int i, j, max = 0;
	std::vector<int> lis(n, 1);//lis = (int*) malloc ( sizeof( int ) * n );


	/* Compute optimized LIS values in bottom up manner */
	for ( i = 1; i < n; i++ )
		for ( j = 0; j < i; j++ )
			if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;

	/* Pick maximum of all LIS values */
	for ( i = 0; i < n; i++ )
		if ( max < lis[i] )
			max = lis[i];

	return max;
}

int StringUtil::longestIncreasingSequenceWithDp( vector<int> & arr, int n, vector<int> & sequence)
{
	sequence.clear();
	int i, j, max = 0;
	std::vector<int> lis(n, 1);

	int iterationCount = 0;
	/* Compute optimized LIS values in bottom up manner */
	for ( i = 1; i < n; i++ )
	{
		for ( j = 0; j < i; j++ )
		{
			iterationCount++;
			if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
			}
		}
	}

	/* Pick maximum of all LIS values */
	for ( i = 0; i < n; i++ )
	{
		if ( max < lis[i] )
		{
			max = lis[i];
		}
	}

	return max;
}
