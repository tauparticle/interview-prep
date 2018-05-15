package SimpleProblems;

import java.util.HashMap;

public class RankAges {
	
	
	public static int FindYearWithMostLivingPersons(int[] birthYears, int[] deathYears)
	{
		int maxCount = -1;
		int maxIndex = -1;
		HashMap<Integer, Integer> histogram = new HashMap<Integer, Integer>();
		
		for(int i=0; i<birthYears.length; ++i) {
			
			for (int j=birthYears[i]; j<deathYears[i]; ++j) {
				
				int numberOfPpl = -1;
				if (!histogram.containsKey(j)) {
					histogram.put(j, 1);
					numberOfPpl = 1;
				}
				else {
					numberOfPpl = histogram.get(j);
					numberOfPpl++;
					histogram.put(j, numberOfPpl);					
				}			
				
				if (numberOfPpl > maxCount) {
					maxCount = numberOfPpl;
					maxIndex = i;
				}
			}
		}
		
		return maxIndex;
		
	}

	public static void main(String[] args) {
		int[] birthYears = new int[10];
		int[] deathYears = new int[10];
		

		birthYears[0] = 1990; deathYears[0] = 2000;
		birthYears[1] = 1991; deathYears[1] = 2000;
		birthYears[2] = 1992; deathYears[2] = 2000;
		birthYears[3] = 1993; deathYears[3] = 2000;
		birthYears[4] = 1994; deathYears[4] = 2000;
		birthYears[5] = 1995; deathYears[5] = 2000;
		birthYears[6] = 1990; deathYears[6] = 1995;
		birthYears[7] = 1991; deathYears[7] = 1994;
		birthYears[8] = 1992; deathYears[8] = 1993;
		birthYears[9] = 1993; deathYears[9] = 1993;

		
		
		/*for(int i=0; i<birthYears.length; ++i) {
			int age = (int)(Math.random() * 100);
			int start = (int)(Math.random() * 2000);
			birthYears[i] = start;
			deathYears[i] = start + age;
		}*/
		
		for(int i=0; i<birthYears.length; ++i) {
			int age = deathYears[i] - birthYears[i];
			System.out.println("born " + birthYears[i] + "-" + deathYears[i] + " age " + age);
		}
		
		int maxYear = FindYearWithMostLivingPersons(birthYears, deathYears);
		System.out.println("Max year is " + birthYears[maxYear]);

	}

}
