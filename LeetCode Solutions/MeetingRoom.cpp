/**

Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return false.

Hide Company Tags Facebook
Hide Tags Sort
Hide Similar Problems (H) Merge Intervals (M) Meeting Rooms II


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

    static bool IntervalCompare(Interval& a, Interval& b)
    {
        return a.start < b.start || (a.start == b.start && a.end < b.end);
    }
    
    bool canAttendMeetings(vector<Interval>& intervals) {
        
        if (intervals.size() < 2) return true;
        sort(intervals.begin(), intervals.end(), IntervalCompare);
        
        for (int i=0; i<intervals.size()-1; ++i)
        {
            auto now = intervals[i];
            auto next = intervals[i+1];
            if (now.end > next.start || now.start == next.start)
            {
                return false;
            }
        }
        
        return true;
        
    }
};