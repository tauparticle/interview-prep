package SimpleProblems;

public class IsNumPowerOfThree {
	
	// generic optimal solution for checking if a number is a power of N
	public static boolean IsPowOfN(int value, int n) {
		
		if (value == 0) return false;
		
		while (value % n == 0) {
			value /= n;
		}
		
		return value == 1;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.println("27 is pow of 3 = " + IsPowOfN(27, 3));
		System.out.println("1 is pow of 5 = " + IsPowOfN(1, 5));
		System.out.println("5 is pow of 5 = " + IsPowOfN(5, 5));
		System.out.println("625 is pow of 5 = " + IsPowOfN(625, 5));
		System.out.println("16807 is pow of 7 = " + IsPowOfN(16807, 7));
		System.out.println("1 is pow of 7 = " + IsPowOfN(1, 7));
		System.out.println("0 is pow of 3 = " + IsPowOfN(0, 3));
		
		
		

	}

}
