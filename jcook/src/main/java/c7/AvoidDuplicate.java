package c7;

import java.util.HashSet;
import java.util.Set;

public class AvoidDuplicate {

	public static void main(String[] args) {

		Set<String> hashSet = new HashSet<>();
		hashSet.add("one");
		hashSet.add("one"); // 오류는 없고 저장만 안됨.
		hashSet.add("two");
		hashSet.forEach(s -> System.out.println(s));
		
	}

}
