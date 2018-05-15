/*
56. Merge Intervals   QuestionEditorial Solution  My Submissions
Total Accepted: 87872
Total Submissions: 320046
Difficulty: Hard
Contributors: Admin
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

Hide Company Tags LinkedIn Google Facebook Twitter Microsoft Bloomberg Yelp
Hide Tags Array Sort
Hide Similar Problems (H) Insert Interval (E) Meeting Rooms (M) Meeting Rooms II


*/
/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    public List<Interval> merge(List<Interval> intervals) {
        
        if (intervals.size() == 0) return intervals;
        
        Collections.sort(intervals, new Comparator<Interval>()
        {
           public int compare(Interval int1, Interval int2)
           {
               return Integer.compare(int1.start, int2.start);
           }
        });
        
        ArrayList<Interval> merged = new ArrayList<Interval>();
        
        Interval prev = intervals.get(0);
        for (int i=1; i < intervals.size(); ++i)
        {
            Interval curr = intervals.get(i);
            if (curr.start <= prev.end)
            {
                prev = new Interval(prev.start, Math.max(curr.end, prev.end));
            }
            else
            {
                merged.add(prev);
                prev = curr;
            }
        }
        
        merged.add(prev);
        return merged;
        
        
    }
}