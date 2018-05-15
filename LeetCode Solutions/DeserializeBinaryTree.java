// java.util.* has been imported for this problem.
// You don't need any other imports.

/*
 Examples:
 
 Compressed String : "1,2,3"
 Output Tree:
   1
  / \
 2   3
 
 Compressed String : "1,2,3,4,*,6,*"
 Output Tree:
    1
   / \
  2   3
 /   /
 4   6
 
 Compressed String : "1,*,2,*,*,*,3"
 Output Tree:
    1
     \
      2
       \
         3

 */

public TreeNode decompressTree(String str){

    if (str == null || str.isEmpty() || str.equals("*")) return null;

    ArrayList<Integer> nums = new ArrayList<Integer>();
    String[] strArr = str.split(",");
    for(String s : strArr)
    {
        nums.add(s.equals("*") ? null : Integer.valueOf(s));
    }

    TreeNode head = new TreeNode(nums.get(0));
    Queue<TreeNode> parents = new LinkedList<TreeNode>();
    parents.offer(head);

    int i=0;
    int size = nums.size();
    while (i < size)
    {
        TreeNode n = parents.poll();
        if (n == null)
        {
            i += 2;
        }
        else
        {
            Integer leftVal = (i+1 < size) ? nums.get(i+1) : null;
            Integer rightVal = (i+2 < size) ? nums.get(i+2) : null;
            TreeNode left = leftVal != null ? new TreeNode(leftVal) : null;
            TreeNode right = rightVal != null ? new TreeNode(rightVal) : null;
            n.left = left;
            n.right = right;
            parents.offer(left);
            parents.offer(right);
            i += 2;
        }
    }

    return head;
}