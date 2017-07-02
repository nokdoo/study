package c7;

import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Collection;

public class Iterate {

	public static void main(String[] args) {
		Collection<String> c = Arrays.asList("One", "Two", "Three");
		c.forEach(s -> System.out.println(s));
		
	}

}
