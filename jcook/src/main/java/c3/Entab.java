package c3;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.PrintWriter;
import c3.Tabs;

public class Entab {

	protected Tabs tabs;
	
	public int getTabSpacing(){
		return tabs.getTabSpacing();
	}
	
	public static void main(String[] argv) throws IOException{
		Entab et = new Entab(8);
		if(argv.length == 0)
			et.entab(
					new BufferedReader(new InputStreamReader(System.in)),
					System.out);
		else
			for(String fileName : argv){
				et.entab(
						new BufferedReader(new FileReader(fileName)),
						System.out);
			}
	}
	
	public Entab(int n){
		tabs = new Tabs(n);
	}
	
	public Entab(){
		tabs = new Tabs();
	}
	
	public void entab(BufferedReader is, PrintWriter out) throws IOException{
		String line;
		
		while((line = is.readLine()) != null){
			out.println(entabLine(line));
		}
	}
	
	public void entab(BufferedReader is, PrintStream out) throws IOException{
		entab(is, new PrintWriter(out));
	}
	
	public String entabLine(String line){
		int N = line.length(), outCol = 0;
		StringBuffer sb = new StringBuffer();
		char ch;
		int consumedSpaces = 0;
		
		for(int inCol = 0; inCol < N; inCol++){
			ch = line.charAt(inCol);
			if(ch == ' '){
				System.out.println("space : Got space at " + inCol);
				if(!tabs.isTabStop(inCol)){
					consumedSpaces++;
				}else{
					System.out.println("tab : Got a Tab Stop " + inCol);
					sb.append('\t');
					outCol += consumedSpaces;
					consumedSpaces = 0;
				}
				continue;
			}
			
			while(inCol-1 > outCol){
				System.out.println("pad : Padding space at "+inCol);
				sb.append(' ');
				outCol++;
			}
			
			sb.append(ch);
			outCol++;
		}
		
		for(int i =0; i < consumedSpaces; i++){
			System.out.println("trail : Padding space at end # " + i);
			sb.append(' ');
		}
		return sb.toString();
	}
}
