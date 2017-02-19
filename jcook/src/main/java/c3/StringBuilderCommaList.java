package c3;

import java.util.StringTokenizer;

public class StringBuilderCommaList {

	public static void main(String a[]) {
		StringBuilder sb1 = new StringBuilder();
		for (String word : "ha1 ha2 ha3 ha4".split(" ")) {
			if (sb1.length() > 0) {
				System.out.println(sb1.length());
				sb1.append(", ");
			}
			sb1.append(word);
		}
		System.out.println(sb1);
		System.out.println("=========================");
		
		// Method using a StringTokenizer
		StringTokenizer st = new StringTokenizer("ha1 ha2 ha3 ha4");
		StringBuilder sb2 = new StringBuilder();
		while (st.hasMoreElements()) {
			sb2.append(st.nextToken());
			if (st.hasMoreElements()) {
				sb2.append(", ");
			}
		}
		System.out.println(sb2);
		
		// Methos using boolean flag
		Boolean flag = false;
		StringTokenizer st3 = new StringTokenizer("ha1 ha2 ha3 ha4");
		StringBuilder sb3 = new StringBuilder();
		while (st.hasMoreElements()) {
			sb2.append(st.nextToken());
			if (st.hasMoreElements()) {
				sb2.append(", ");
			}
		}
		System.out.println(sb2);
		
	}

}
