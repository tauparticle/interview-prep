/*
 You are given a String containing at least 4 numbers that represented an IPv4 Address, but the separator data - i.e. the dots that separate each Byte in a 4 Byte Ipv4 address, has been lost. Write a method - generateIPAddrs that takes in this String and returns an ArrayList of Strings containing all possible IPv4 Addresses that can be generated from the given sequence of decimal integers.
 
 
 Note:
 
 - The IP Addresses for this problem are written in the decimal dot notation.
 - You must use all the digits in the input String
 - The order in which the IP Addresses are returned does not matter
 - 0.0.0.1 and 0.0.0.01 may be considered 2 distinct possibilities. i.e. do not ignore leading or trailing 0s.
 
 Examples:
 
 generateIPAddrs("0001") ==> {"0.0.0.1"}
 
 generateIPAddrs("0010") ==> {"0.0.1.0"}
 
 generateIPAddrs("25525511135") ==> {"255.255.11.135", "255.255.111.35"}
 
 */

public static ArrayList<String> generateIPAddrs(String input)
{
	  class IpLevelNode {
	    public int level = 0;
	    public String predecessor;
	    public String successor;

	    public IpLevelNode(int level, String ipToAppend, String predecessor, String successor) {
	      this.level = level;
	      this.successor = successor;
	      if (level == 0) {
	          this.predecessor = ipToAppend;
	      } else {
	          this.predecessor = predecessor + "." + ipToAppend;
	      }
	    }
	  }
	  
	  ArrayList<String> out = new ArrayList<>();
	  Deque<IpLevelNode> stack = new LinkedList<>();
	  // Push 3 possibilities onto the stack
	  stack.addFirst(new IpLevelNode(0, input.substring(0,1),"", input.substring(1)));
	  stack.addFirst(new IpLevelNode(0, input.substring(0,2),"", input.substring(2)));
	  stack.addFirst(new IpLevelNode(0, input.substring(0,3),"", input.substring(3)));

	  while(!stack.isEmpty()){
	    IpLevelNode node = stack.removeFirst();
	    int curlevel = node.level;
	    String predecessor = node.predecessor;
	    String remaining = node.successor;
	    if(curlevel == 3 && remaining.length() == 0){
	        out.add(node.predecessor);
	        continue;
	    }
	    int i = 1;
	    while(i <= 3){
	      if(remaining.length() < i) break;
	      String ipToAppend = remaining.substring(0,i);
	      String successor = remaining.substring(i);
	      if(ipToAppend.length() > 0){
	        int numIpToAppend = Integer.parseInt(ipToAppend);
	        if(numIpToAppend <= 255) stack.addFirst(new IpLevelNode(curlevel+1,ipToAppend,predecessor,successor));
	      }
	      i++;
	    }
	  }
	  return out; 
}