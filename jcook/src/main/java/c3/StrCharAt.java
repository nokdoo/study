package c3;

public class StrCharAt {
	public static void main(String[] av) {
		String a = "A quick bronze fox lept a lazy bovine";
		for (int i = 0; i < a.length(); i++) // Don't use foreach
			//System.out.println("Char " + i + " is " + a.charAt(i));
		;
		String test = "한글은 어떻게 되려나";
		for(int i = 0; i<test.length(); i++){
			System.out.print(test.charAt(i));
		}
	}
}