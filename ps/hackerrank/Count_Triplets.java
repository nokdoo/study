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

public class Count_Triplets {

	// Complete the countTriplets function below.
	static long countTriplets(List<Long> arr, long r) {
		final long count[] = new long[] {0};
		Map<Long, Long> map = new HashMap<Long, Long>();
		Map<Long, Long> map2 = new HashMap<Long, Long>();

		arr.forEach((item) -> {
			if(item % r == 0)
			{
				long tmp = item/r;
				if(map2.containsKey(tmp))
				{
					count[0] += map2.get(tmp);

				}
				
				if(map.containsKey(tmp))
				{
					map2.put(item, map2.getOrDefault(item, 0)+map.get(tmp));
				}
			}
			
			if(!map.containsKey(item))
				map.put(item, 1);
			else
				map.put(item, map.get(item)+1);
		});
		
		return count[0];

	}

	public static void main(String[] args) throws IOException {
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

		String[] nr = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

		int n = Integer.parseInt(nr[0]);

		long r = Long.parseLong(nr[1]);

		List<Long> arr = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
			.map(Long::parseLong)
			.collect(toList());

		long ans = countTriplets(arr, r);

		bufferedReader.close();
		System.out.println(ans);
	}
}
