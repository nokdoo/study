import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Q1463{
	
	static int[] map = null;
	
	public static int ApplyOperators(int n){
		if(map[n-1] != 0) return map[n-1];
		
		for(int i=4; i<=n; i++) {
			map[i-1] = map[i-1-1] + 1;
			
			if(i%3 == 0){
				map[i-1] = Math.min(map[i/3 -1] + 1, map[i-1]);
			}
			
			if(i%2 == 0){
				map[i-1] = Math.min(map[i/2 -1] + 1, map[i-1]);
			}
		}
		
		return map[n-1];
	}
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine().trim());
		
		map = new int[n];
		if(n<3) {
			for(int i=0; i<n; i++) {
				map[i] = 1;
			}
		}else {
			map[0] = 1;
			map[1] = 1;
			map[2] = 1;
		}
		
		int times;
		if(n <=3) {
			times= map[n-1];
		}else {
			times = ApplyOperators(n);
		}
        System.out.println(times);
	}
}