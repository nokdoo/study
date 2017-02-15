package c3;

import java.util.StringTokenizer;

public class SubStringDemo {

	public static void main(String av[]){
		String a = "Java is great.";
		System.out.println(a.substring(5));
		
		/*StringTokenizer st = new StringTokenizer("Hello World of Java");
		while (st.hasMoreTokens( ))
		System.out.println("Token: " + st.nextToken(
		));*/
		
		StringTokenizer st2 = new StringTokenizer("Hello, World|of|Java", ", |", true);
				while (st2.hasMoreElements( ))
				System.out.println("Token: " + st2.nextElement(
				));
	}
	
}
