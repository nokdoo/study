import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Q2011 {

	public static void GG() {
		System.out.println(0);
		System.exit(1);
	}

	public static int Solution(String pass) {
		String lastTwo = pass.substring(pass.length() - 2);
		if (Integer.parseInt(lastTwo) > 30 || pass.charAt(0) == '0')
			GG();

		return Count(pass);
	}

	public static int Count(String pass) {
		int map[] = new int[pass.length()];
		map[0] = 1;
		
		if(pass.charAt(2) != '0') {
			map[1] = 1;
		}
		
		if(IsTwo(pass, 1))
			map[1] = map[1] + map[0];
		
		
		for(int i=2; i<map.length; i++) {
			if(pass.charAt(i)!='0') {
				map[i] = map[i-1] + map[i];
				map[i] %= 1000000;
			}
			
			if(IsTwo(pass, i)) {
				map[i] = map[i-2] + map[i];
				map[i] %= 1000000;
			}
		}
		
		return map[pass.length()-1];
	}
	
	public static boolean IsTwo(String pass, int i) {
		int value = Integer.parseInt(pass.substring(i-1, i+1));
		
		if(value >=10 && value <= 26) {
			return true;
		}
		return false;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String pass = br.readLine().trim();
		System.out.println("asd".substring(1, 3));
		int answer = Solution(pass);
		System.out.println(answer);
	}

}
