// java.util.* has been imported for this problem.
// You don't need any other imports.


/* Given a string, list all possible combinations and permutations of its characters.
 
 Examples:
 getCombPerms("a") ==> {"a"}
 
 getCombPerms("ab") ==> {"a","ab","ba","b"}
 
 
 */


// Just like permutations, but also include the non-merged subsets
// O(n!) runtime and O(!n) space
public static ArrayList<String> getCombPerms(String s) {

    if (s == null)
    {
        // error case
        return null;
    }

    ArrayList<String> set = new ArrayList<String>();
    if (s.length() == 1)
    {
        // base case
        set.add(s);
        return set;
    }

    char prefix = s.charAt(0);
    String suffix = s.substring(1);

    set.add(String.valueOf(prefix));

    ArrayList<String> subSets = getCombPerms(suffix);

    for (String str : subSets)
    {
        for (int i=0; i <= str.length(); ++i)
        {
            set.add(insertCharToIndex(str, prefix, i));
        }
    }

    set.addAll(subSets);

    return set;
}

private static String insertCharToIndex(String s, char c, int i)
{
    return s.substring(0, i) + c + s.substring(i);
}