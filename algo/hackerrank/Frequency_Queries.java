import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

public class Frequency_Queries {

    // Complete the freqQuery function below.
    static List<Integer> freqQuery(List<int[]> queries) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        Map<Integer, Integer> map2 = new HashMap<Integer, Integer>();

        List<Integer> result = new ArrayList<Integer>();

        queries.forEach(array -> {
            Integer command = array[0];
            Integer value = array[1];

            if(command == 1)
            {
                int map_value;
                if(map.containsKey(value))
                {
                    map_value = map.get(value);
                
                    map.put(value, map_value+1);

                    map2.put(map_value+1, map2.getOrDefault(map_value+1, 0) + 1);
                    map2.put(map_value, Math.max(0, map2.get(map_value)-1));

                }
                else
                {
                    map.put(value, 1);
                    map2.put(1, map2.getOrDefault(1, 0)+1);
                }
            }
            else if(command == 2)
            {
                int map_value;
                if(map.containsKey(value))
                {
                    map_value = map.get(value);
                    map.put(value, Math.max(0, map_value-1));

                    map2.put(map_value, Math.max(0, map2.get(map_value)-1));
                    map2.put(map_value-1, map2.getOrDefault(map_value-1, 0) + 1);
                }
            }
            else if(command == 3)
            {
                if(map2.containsKey(value) && map2.get(value)>0)
                    result.add(1);
                else
                    result.add(0);
            }
        });
        return result;
    }

    public static void main(String[] args) throws IOException {
    try (BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in))) {
      int q = Integer.parseInt(bufferedReader.readLine().trim());
      List<int[]> queries = new ArrayList<>(q);
      Pattern p  = Pattern.compile("^(\\d+)\\s+(\\d+)\\s*$");
      for (int i = 0; i < q; i++) {
        int[] query = new int[2];
        Matcher m = p.matcher(bufferedReader.readLine());
        if (m.matches()) {
          query[0] = Integer.parseInt(m.group(1));
          query[1] = Integer.parseInt(m.group(2));
          queries.add(query);
        }
      }
      List<Integer> ans = freqQuery(queries);
      try (BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(new File("output.txt")))) {
        bufferedWriter.write(
                ans.stream()
                        .map(Object::toString)
                        .collect(joining("\n"))
                        + "\n");
      }
    }
  }
}
