package c4;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ReplaceDemo {

	public static void main(String[] args) {

		String patt = "\\bfavor\\b";
		
		String input = "Do me a favor? Fetch my favorite.";
		System.out.println("Input : " + input);
		Pattern r = Pattern.compile(patt);
		Matcher m = r.matcher(input);
		System.out.println("ReplaceAll: " + m.replaceAll("favour"));
		m.reset();
		
		StringBuffer sb = new StringBuffer();
		System.out.print("Append methods: ");
		while(m.find()){
			m.appendReplacement(sb,  "favour");
		}
		m.appendTail(sb);
		System.out.println(sb.toString());
	}

}
