import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.stream.Collectors;


public class Q11055{

	public static void SetMax(int[] arr, int[] max, int i){
		int last_index = arr.length-1;
		int maxxx = 0;
		if(i == last_index){
			max[i] = arr[last_index];
		}

		for(int j=i+1; j<=last_index; j++){
			if(arr[j] > arr[i]){
				maxxx = Math.max(maxxx, max[j]);
			}
		}
		max[i] = maxxx + arr[i];
	}

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine().trim());
		int[] max = new int[n];
		
		int[] arr = Arrays.stream(br.readLine().trim().split(" "))
			.mapToInt(Integer::valueOf)
			.toArray();

		for(int i=n-1; i>=0; i--){
			SetMax(arr, max, i);
		}

		int answer = 0;
		for(int i=0; i<n; i++){
			answer = Math.max(answer, max[i]);
		}
		System.out.println(answer);
	}
}

