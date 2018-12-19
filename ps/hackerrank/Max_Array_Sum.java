import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.io.IOException;
import java.io.File;
import java.io.FileWriter;

public class Max_Array_Sum
{
	static int maxSubsetSum(int[] arr)
	{
		int len = arr.length;
        int[] sumArray = new int[len];
        sumArray[0] = Math.max(0, arr[0]);
        sumArray[1] = Math.max(sumArray[0], arr[1]);

        for(int i = 2; i<len; i++)
        {
            sumArray[i] = Math.max(sumArray[i-1], sumArray[i-2]+arr[i]);
        }

        return sumArray[len-1];
	}

	public static void main(String[] args) throws IOException
	{
		int size = 0;
		int[] array = null;
		try(BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in)))
		{
			size = Integer.parseInt(bufferedReader.readLine().trim());
			array = Arrays.stream(bufferedReader.readLine().trim().split(" "))
						.mapToInt(Integer::parseInt)
						.toArray();
		}

		int res = maxSubsetSum(array);

		//try(BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH"))))
		try(BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(new File("output.txt"))))
		{
			bufferedWriter.write(String.valueOf(res));
	        bufferedWriter.newLine();
		}
	}
}
