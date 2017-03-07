package c3;

import java.util.ArrayList;
import java.util.List;

public class CSV {

	public static final char DEF_DEL = ',';
	protected char sep;
	protected List<String> list = new ArrayList<>();
	
	public CSV(){
		this(DEF_DEL);
	}
	
	public CSV(char del){
		this.sep = del;
	}
	
	public List<String> parse(String line){
		StringBuffer sb = new StringBuffer();
		list.clear();
		int i = 0;
		int len = line.length();
		char c;
		
		if(len == 0){
			list.add(line);
			return list;
		}
		
		while(i < len){
			sb.setLength(0);
			if((c = line.charAt(i)) == '"'){
				i = inQuote(i+1, sb, line);
			}else{
				i = outQoute(i, sb, line);
			}
			list.add(sb.toString());
			i++;
		}
		
		/*do{
			if(i < len && line.charAt(i) != '"'){
				//문자열을 만날때까지 처
			}else{
				//"를 만나면서 문자열을 끝날때까지 처리 
			}
		}while(i < len);*/
		return list;
	}
	
	private int inQuote(int i, StringBuffer sb, String line){
		int len = line.length();
		char c;
		while(i < len){

			if((c = line.charAt(i)) != '"'){
				sb.append(c);
			}else{
				break;
			}
			i++;
		}
		return i;
	}
	
	private int outQoute(int i, StringBuffer sb, String line){
		int len = line.length();
		char c;
		while(i < len){
			if((c = line.charAt(i)) == DEF_DEL){
				break;
			}else{
				sb.append(c);
			}
			i++;
		}
		return i;	
	}
}