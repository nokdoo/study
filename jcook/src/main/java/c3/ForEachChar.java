package c3;

public class ForEachChar {
	public static void main(String[] args) {
		String s = "한글도 배열로 분리가 될까나?";
		// for (char ch : s) {...} Does not work, in Java 7
		for (char ch : s.toCharArray()) {
			//System.out.println(ch);
		}
		
		char arr[] = s.toCharArray();
		
		int len = arr.length;
		
		for(int i=0; i<len; i++){
			System.out.print(arr[i]);
		}
		
		
	}
}