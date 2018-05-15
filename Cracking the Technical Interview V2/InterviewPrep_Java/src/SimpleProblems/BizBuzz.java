package SimpleProblems;

public class BizBuzz {
	
	public static void PlayFizzBuzz(int count) {
		
		for (int i=1; i<=count; ++i) {
			if (i % 5 == 0 && i % 3 == 0) {
				System.out.println("FizzBuzz");
			}
			else if (i % 5 == 0) {
				System.out.println("Fizz");
			}
			else if (i % 3 == 0) {
				System.out.println("Buzz");
			}
			else {
				System.out.println(i);
			}
			
			
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		PlayFizzBuzz(100);
	}

}
