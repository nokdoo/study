package c4;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class REmatchTwoFields {

	public static void main(String[] args) {

		String inputLine = "Adams, John Quincy";
		Pattern r = Pattern.compile("(.*), (.*)");
		Matcher m = r.matcher(inputLine);
		if(!m.matches()){
			throw new IllegalArgumentException("Bad Input");
		}
		System.out.println(m.group(2) + ' ' + m.group(1));
		System.out.println(m.group(0));
	}

}
