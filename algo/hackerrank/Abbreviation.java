import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Abbreviation {

    static String pattern = "[a-z]*";
    static Pattern p = Pattern.compile(pattern);
    static HashMap<Long, Boolean> map; 

    static Long hash(int a, int b)
    {
        return a * 10000l + b;
    }

	public static boolean abbreviation(char[] a, char[] b, int ia, int ib)
	{
		if(map.containsKey(hash(ia, ib)))
		{
			return map.get(hash(ia, ib));
		}

		if(ia == a.length)
		{
			if(ib == b.length) return true;
			else return false;
		}

		if(ib == b.length)
		{
			Pattern p = Pattern.compile(pattern);
			Matcher m = p.matcher(new String(a, ia, a.length-ia));
			if(m.matches()) return true;
			else return false;
		}

		if(Character.isUpperCase(a[ia]))
		{
			if(a[ia] == b[ib]) return abbreviation(a, b, ia+1, ib+1);
			else return false;
		}
		else
		{
			if(Character.toUpperCase(a[ia]) == b[ib])
			{
				Boolean result1 = abbreviation(a, b, ia+1, ib+1);
				map.put(hash(ia+1, ib+1), result1);
				Boolean result2 = abbreviation(a, b, ia+1, ib);
				map.put(hash(ia+1, ib), result2);
				return result1 || result2;
			}
			else
			{
				return abbreviation(a, b, ia+1, ib);
			}
		}
	}

    public static void main(String[] agrs) throws IOException
    {
        int q;
        try
        (
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
            //BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));
            BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(new File("output.txt")));
        )
        {
            q = Integer.parseInt(bufferedReader.readLine().trim());

            for(int i=0; i<q; i++)
            {
				map = new HashMap<Long, Boolean>();
                char[] a = bufferedReader.readLine().trim().toCharArray();
                char[] b = bufferedReader.readLine().trim().toCharArray();

                boolean result = abbreviation(a, b, 0, 0);
                if(result == true) bufferedWriter.write("YES");
                else bufferedWriter.write("NO");
                bufferedWriter.newLine();
            }
        }
    }
}

