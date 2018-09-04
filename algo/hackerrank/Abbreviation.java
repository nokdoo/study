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
    static HashMap<Long, Boolean> map = new HashMap<Long, Boolean>();

    static Long hash(int a, int b)
    {
        return a * 10000l + b;
    }

    static boolean subAbbreviation(String a, String b, int idx_a, int idx_b)
    {
        if(a.length() == idx_a) return false;
        if(Character.toUpperCase(a.charAt(idx_a)) == b.charAt(idx_b)) return true;
        else return false;
    }

    static boolean abbreviation(String a, String b, int idx_a, int idx_b)
    {
        if(map.containsKey(hash(idx_a, idx_b)))
            return map.get(hash(idx_a, idx_b));

        boolean result = false;
        if(b.length() == idx_b)
        {
            Matcher m = p.matcher(a.substring(idx_a));
            if(m.matches()) result = true;
            else result = false;
            return result;
        }

        if(a.length() == idx_a)
        {
            if(b.length() == idx_b) result = true;
            else result = false;
            return result;
        }

        if(Character.toUpperCase(a.charAt(idx_a)) == b.charAt(idx_b))
        {
            if(Character.isLowerCase(a.charAt(idx_a)))
            {
                if(subAbbreviation(a, b, idx_a+1, idx_b))
                {
                    result = (abbreviation(a, b, idx_a+1, idx_b) || abbreviation(a, b, idx_a+1, idx_b+1));
                    //map.put(hash(idx_a, idx_b), result);
                }
                else result = abbreviation(a, b, idx_a+1, idx_b+1);
            }
            else
            {
                result = abbreviation(a, b, idx_a+1, idx_b+1);
            }
            return result;

        }
        else
        {
            if(Character.isLowerCase(a.charAt(idx_a))) 
                result = abbreviation(a, b, idx_a+1, idx_b);
            else
                result = abbreviation(a, b, idx_a-idx_b+1, 0);
            return result;
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
                String a = bufferedReader.readLine().trim();
                String b = bufferedReader.readLine().trim();

                boolean result = abbreviation(a, b, 0, 0);
                if(result == true) bufferedWriter.write("YES");
                else bufferedWriter.write("NO");
                bufferedWriter.newLine();
            }
        }
    }
}

