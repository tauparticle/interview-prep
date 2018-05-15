/*A peak element is an element that is greater than its neighbors.

Given an input array where num[i] != num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -infini.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

Peak element can be like a hill climb, and there can be multiple hill peaks.  
[/\/\/\]
*/

class Solution {
public:
	int findPeakElement(const vector<int> &num) {
		int len = num.size();
		if (len == 1) return 0;
		int left = 0, right = len - 1;
		int mid;
		while (left < right - 1) {
			mid = (left + right) / 2;
			if (num[mid] > num[mid - 1] && num[mid] > num[mid + 1]) return mid;
			if (num[mid] < num[mid - 1]) right = mid;  // like hill climbing 
			else left = mid;
		}
		return num[left] > num[right] ? left : right;
	}
};