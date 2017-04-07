package c4;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class REmatch2 {
	public static void main(String argv[]){
		String patt = "Q[^u]\\d+\\.";
		Pattern r = Pattern.compile(patt);
		String line = "Order QT300. NOW!";
		Matcher m = r.matcher(line);
		if(m.find()){
			System.out.println(patt+" matches \""+
					line.substring(m.start(0), m.end(0))+
							"\" in \"" + line + "\"");
		}else{
			System.out.println("NO MATCH");
		}
	}
}
