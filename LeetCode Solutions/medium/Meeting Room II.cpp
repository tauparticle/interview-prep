/*
253. Meeting Rooms II   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 24208
Total Submissions: 63987
Difficulty: Medium
Contributors: Admin
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.

Hide Company Tags Google Snapchat Facebook
Hide Tags Heap Greedy Sort
Hide Similar Problems (H) Merge Intervals (E) Meeting Rooms (M) Minimum Number of Arrows to Burst Balloons
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    
    
    // O(n log n) runtime
    // O(n) space
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start(intervals.size(), 0);
        vector<int> end(intervals.size(), 0);
        for (int i=0; i<intervals.size(); ++i)
        {
            start[i] = intervals[i].start;
            end[i] = intervals[i].end;
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int si = 0;
        int ei = 0;
        int i = 0;
        int count = 0;
        while (i++ < intervals.size())
        {
            if (end[ei] > start[si])
            {
                count++;
            }
            else
            {
                ei++;
            }
            si++;
        }
        return count;
    }
};
