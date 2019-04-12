import java.util.Scanner;

public class CountSort {

	public static Scanner sc = new Scanner(System.in);
	
	public static void main(String[] args) {
		
		// 0-7
		int[] data = new int[]{
			0,4,1,3,1,2,4,1,7
		};
		// allocating array for sorted data
		int[] sortedData = new int[data.length];
		
		// for 0-7
		int sizeOfRange = 8; 
		int[] counts = new int[sizeOfRange];
		
		// counting each datum
		for (int i=0; i<data.length; i++) {
			counts[data[i]]++;
		}
		
		// step-by-step summing
		for ( int i=1; i<counts.length; i++ ) {
			counts[i] = counts[i] + counts[i-1];
		}
		
		for ( int i=0; i<data.length; i++ ) {
			int idx = --counts[data[i]];
			sortedData[idx] = data[i];
		}
		
		System.out.println(); 
		
		sc.close();
	}

}
