package c7;

import java.sql.Date;
import java.util.Arrays;
import java.util.List;

public class Array2 {
	public final static int INITIAL = 10, GROW_FACTOR = 2;

	public static void main(String[] argv) {
		List<String> firstNames = Arrays.asList("Roin", "Jame", "Jey");
		System.out.println(firstNames);
		List<String> secondNames = Arrays.asList(new String[]{"Roin", "Jame", "Jey"});
		System.out.println(secondNames);
		String[] test = new String[]{"Roin", "Jame", "Jey"};
		System.out.println(test[0]);
	}
}
