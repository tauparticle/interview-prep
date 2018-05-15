package Bits;

public class CountOnes {
	
	// there are probably much faster ways to do this, but is the easiest to read
	public static int CountNumOnes(int num)
	{
		int count = 0;
		while (num > 0) {
			if ((num & 1) != 0) {
				count++;
			}
			num = num >> 1;
		}
		return count;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("65535 = " + CountNumOnes(65535));

	}

}
