package c4;

public class AutoboxDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int i = 42;
		int result = foo(i);
		System.out.println(result);
		Integer j = Integer.valueOf(42);
				
	}
	public static Integer foo(Integer i){
		System.out.println("Object = " + i);
		return Integer.valueOf(123);
	}
}
