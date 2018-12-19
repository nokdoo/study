import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.FileWriter;
import java.io.File;
import java.util.HashMap;

public class Recursion_Davis_Staircase
{
	static HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();

	static int stepPerms(int n)
	{
		int tmp;
		if(map.containsKey(n))
		{
			return map.get(n);
		}

		int result = 0;
		if(n < 0) return result;
		if(n == 0) return 1;

		if(n>=3)
		{
			tmp = stepPerms(n-3);
			map.put(n-3, tmp);
			result += tmp; 
		}
		if(n>=2)
		{
			tmp = stepPerms(n-2);
			map.put(n-2, tmp);
			result += tmp; 
		}
		if(n>=1)
		{
			tmp = stepPerms(n-1);
			map.put(n-1, tmp);
			result += tmp; 
		}
		
		return result;
	}

	public static void main(String[] args) throws IOException
	{
		int s;
		try(
			BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(new File("output.txt")));
			//BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));
		)
		{
			s = Integer.parseInt(bufferedReader.readLine().trim());

			for(int i=0; i<s; i++)
			{
				int n = Integer.parseInt(bufferedReader.readLine().trim());
				int result = stepPerms(n);
				bufferedWriter.write(String.valueOf(result));
				bufferedWriter.newLine();
			}
		}

	}
}
