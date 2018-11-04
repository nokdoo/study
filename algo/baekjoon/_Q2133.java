import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Q2133{
	
		public static int Fill(int n){
			int f2 = 3;
			if(n == 2) return 3;
			n = n/2-1;
			return f2 * (int)Math.pow(2, n	) + 6 * ((int)Math.pow(2, n)-1);
		}
	
		public static void main(String[] args) throws IOException{
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			
			int n = Integer.parseInt(br.readLine().trim());
			
			int answer = Fill(n);
			
			System.out.println(answer);
		}
}