import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Q2442{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader
					(System.in));
		int n = Integer.parseInt(br.readLine().trim());

		int k=n;

		for(int i=0; i<n; i++, k--){
			int j=1;
			for(; j<=n; j++){
				if(j>=k){
					System.out.print("*");
				}else{
					System.out.print(" ");
				}
			}
			j--;
			j--;
			for(; j>=1; j--){
				if(j>=k){
					System.out.print("*");
				}else{
					System.out.print(" ");
				}
			}
			System.out.println();
		}

	}
}
