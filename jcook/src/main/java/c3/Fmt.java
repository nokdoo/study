package c3;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Fmt{
	
	final int COLWIDTH = 10;
	PrintWriter out;
	
	public Fmt(BufferedReader br){
		String line;
		StringBuilder sb = new StringBuilder();
		try {
			while((line = br.readLine()) != null){
				StringTokenizer st = new StringTokenizer(line);
				sb.setLength(0);
				while(st.hasMoreTokens()){
					String word = st.nextToken();
					if(sb.length()+word.length() > COLWIDTH){
						sb.append("\n");
						sb.append(word);
					}else{
						sb.append(word);
					}
					sb.append(' ');
				}
				System.out.println(sb.toString());
			}
			
			//out.println(sb.toString());
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args){
		if(args.length == 0){
			System.out.println("input args...");
		}else{
			for(String arg : args){
				try {
					new Fmt(new BufferedReader(new FileReader(Fmt.class.getResource("").getPath()+arg)));
				} catch (FileNotFoundException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
	}
}