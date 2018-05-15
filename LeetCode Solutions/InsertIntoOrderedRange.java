// java.util.* has been imported for this problem.
// You don't need any other imports.

/*
 A Range Module is a module that tracks ranges of numbers. Range modules are used extensively when designing scalable online game maps with millions of players. Your task is to write a method - insertRange that takes in an ArrayList of sorted, non-overlapping integer Interval s (aka ranges) and a new Interval - insert, and returns an ArrayList of sorted Interval s where insert has been added to the ArrayList in the correct spot and the required overlapping ranges have been merged. The Interval class is available by clicking Use Me. Target a time complexity of O(n).
 
 
   class Interval {
      int start;
      int end;
      Interval(int start, int end) {
          this.start = start;
          this.end = end;
      }
  } 
 */

public static ArrayList<Interval> insertRange(ArrayList<Interval> intervalsList, Interval insert) {
    ArrayList<Interval> out = new ArrayList<Interval>();
    
    for (int index=0; index<intervalsList.size(); ++index)
    {
        Interval i = intervalsList.get(index);
        if (i.end < insert.start)
        {
            // less than insert
            out.add(i);
        }
        else if (i.start > insert.end)
        {
            // greater than insert
            out.add(insert);
            insert = i;
        }
        else if ((insert.end >= i.start && insert.end <= i.end) ||
                 (insert.start >= i.start && insert.start <= i.end) ||
                 (insert.start >= i.start && insert.end <= i.end))
        {
            insert = new Interval(Math.min(insert.start, i.start), Math.max(insert.end, i.end));
        }
    }
    
    out.add(insert);
    return out;
}