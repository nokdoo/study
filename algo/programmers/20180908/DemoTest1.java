import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.HashSet;
import java.util.Arrays;

public class DemoTest1
{

	static public String solution(String input)
	{
		Matcher m = p.matcher(input);
		
		HashSet<Long> set = new HashSet<Long>();

		while(m.find)
		{
			Long value = Long.parseLong(m.group(1));
			System.out.println(value + " " + tmp.length);
			if(value <= 0 || value > tmp.length)
                return "false";
			if(set.contains(value))
			{
				return "false";
			}
			else
			{
				set.add(value);
			}
		}

		return "true";

	}

	public static void main(String[] args) throws IOException
	{
		String input = null;
		try
		(
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
		)
		{
			input = bufferedReader.readLine().trim();	
		}

		String output = solution(input);
		System.out.println(output);
	}
}
