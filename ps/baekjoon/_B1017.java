import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;


public class B1017 {
	
	static boolean IsPrimeNumber ( int n ) {
		for ( int i = 2; i <= n/2; i++ ) {
			if ( n % i == 0 ) return false;
		}
		return true;
	}
	
	static boolean FindPairs ( int[] odd, int[] even, int idx, int jdx, int n, HashSet<Integer> set) {
		set.add(even[jdx]);
		if ( set.size() == n ) return true;
		
		for ( jdx=0; jdx<n; jdx++) {
			if ( set.contains(even[jdx]) ) {
				continue;
			}
			if ( IsPrimeNumber(odd[idx]+even[jdx])) {
				return FindPairs(odd, even, idx+1, jdx, n, set);
			}
		}
		
		return false;
	}
	
static ArrayList<Integer> Solution ( int[] number ) {
		
		int i=0, j=0;
		int[] odd = new int[25];
		int[] even = new int[25];
		ArrayList<Integer> answer = new ArrayList<Integer>();
		
		for ( int n : number ) {
			if ( n % 2 == 1 ) {
				odd[i++] = n;
				continue;
			}
			even[j++] = n;
		}
		
		if ( i != j ) {
			answer.add(-1);
			return answer;
		}
		
		
		for ( int jdx=0; jdx<j; jdx++) {
			if ( IsPrimeNumber(odd[0] + even[jdx]) 
					&& FindPairs(odd, even, 0+1, jdx, i, new HashSet<Integer>() ) ) {
				answer.add(even[jdx]);
			}
		}
		
		if(answer.isEmpty()) {
			answer.add(-1);
			return answer;
		}
		
		return answer;
	}
	
	public static void main(String[] args) {
		try ( BufferedReader br = new BufferedReader( new InputStreamReader( System.in ))){
			String line = br.readLine().trim();
			int n = Integer.parseInt( line );
			line = br.readLine().trim();
			String[] input = line.split(" ");
			int i = 0;
			int[] number = new int[n];
			for ( String str : input ) {
				number[i++] = Integer.parseInt(str);
			}
			
			ArrayList<Integer> answer = Solution(number);
			Collections.sort(answer);
			for ( int a : answer) {
				System.out.print(a+" ");
			}
		}catch (Exception e) {
			
		}
	}
	
}
