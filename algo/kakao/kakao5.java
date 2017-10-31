import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Calendar;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;

public class kakao5 {
	
	public static void main(String[] args) throws ParseException {
		
		kakao5 sol = new kakao5();
		System.out.println(sol.getAnswer("FRANCE", "french"));
		System.out.println(sol.getAnswer("handshake", "shake hands"));
		System.out.println(sol.getAnswer("aa1+aa2", "aaaa12"));
		System.out.println(sol.getAnswer("E=M*C^2", "e=m*c^2"));
	}
	
	public int getAnswer(String str1, String str2) {
		str1 = str1.toLowerCase();
		str2 = str2.toLowerCase();
		HashMap<String, Integer> hash1 = new HashMap<String, Integer>();
		HashMap<String, Integer> hash2 = new HashMap<String, Integer>();
		input(str1, hash1);
		input(str2, hash2);
		
		int intersection = getIntersection(hash1, hash2);
		int union = getUnion(hash1, hash2);
		if(intersection == 0 && union == 0) {
			intersection = 1;
			union = 1;
		}
		float result = (float)intersection/(float)union;
		result *= 65536;

		return (int) result;
	}
	
	private int getUnion(HashMap<String, Integer> hash1, HashMap<String, Integer> hash2) {
		int result = 0;
		for(Entry<String, Integer> elem : hash1.entrySet()) {
			if(hash2.containsKey(elem.getKey())) {
				result += Math.max(hash2.get(elem.getKey()), elem.getValue());
				hash2.remove(elem.getKey());
			}else {
				result += elem.getValue();
			}
		}
		
		for(Entry<String, Integer> elem : hash2.entrySet()) {
				result += elem.getValue();
		}
		
		return result;
	}

	private int getIntersection(HashMap<String, Integer> hash1, HashMap<String, Integer> hash2) {
		int result = 0;
		for(Entry<String, Integer> elem : hash1.entrySet()) {
			if(hash2.containsKey(elem.getKey())) {
				result += Math.min(hash2.get(elem.getKey()), elem.getValue());
			}
		}
		return result;
	}

	//# String regex
	public void input(String str, HashMap<String, Integer> hash) {
		String tmp;
		for(int i =0; i<str.length()-1; i++) {
			tmp = str.substring(i, i+2);
			if(tmp.matches("[a-z]{2}")) {
				if(hash.containsKey(tmp)) {
					hash.put(tmp, hash.get(tmp)+1);
				}else {
					hash.put(tmp, 1);
				}
			}
		}
	}
}

class hash2 extends HashMap<String, Integer>{
	public void addValue(int a) {
		
	}
}
