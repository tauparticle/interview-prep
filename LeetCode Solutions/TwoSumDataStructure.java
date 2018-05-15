/*
 Design and implement a TwoSum class. It should support the following operations: add and find.
 
 add - Add the number to an internal data structure.
 find - Find if there exists any pair of numbers which sum is equal to the value.
 
 For example,
 add(1); add(3); add(5);
 find(4) -> true
 find(7) -> false
 */
public class TwoSum {
    
    private HashMap<Integer, Integer> numberCounts = new HashMap<Integer, Integer>();
    
    // Add the number to an internal data structure.
    public void add(int number) {
        if (numberCounts.containsKey(number))
        {
            numberCounts.put(number, numberCounts.get(number)+1);
        }
        else
        {
            numberCounts.put(number, 1);
        }
    }
    
    // Find if there exists any pair of numbers which sum is equal to the value.
    public boolean find(int value) {
        for (Map.Entry<Integer, Integer> entry : numberCounts.entrySet())
        {
            int num = entry.getKey();
            int diff = value - num;
            if (diff == num)
            {
                // For duplicates, ensure there are at least two individual numbers.
                if (entry.getValue() >= 2) return true;
            }
            else if (numberCounts.containsKey(diff))
            {
                return true;
            }
        }
        return false;
    }
}


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum = new TwoSum();
// twoSum.add(number);
// twoSum.find(value);