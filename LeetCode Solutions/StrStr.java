/*
Implement strstr(). Returns the index of the first occurrence of needle in haystack, or –1
if needle is not part of haystack.

There are known efficient algorithms for this like Boyer-Moore, but since they are advanced algorithms, 
They are not good for attempting to solve in interviews.  A direct brute force is sufficient for interviews.

Assume n= length of haystack and m = length of needle
Runtime = O(mn)  Space: O(1)
*/

// O(n) runtime, O(1) space
public class Solution {
	public int strStr(String haystack, String needle) {
		for (int i = 0; ; i++) {
			for (int j = 0; ; j++) {
				if (j == needle.length()) return i;
				if (i + j == haystack.length()) return -1;
				if (needle.charAt(j) != haystack.charAt(i + j)) break;
			}
		}
	}
}