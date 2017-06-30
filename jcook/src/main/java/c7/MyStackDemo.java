package c7;



 public class MyStackDemo{
	public static void main(String... args){
		MyStack<Integer> stack = new MyStack<Integer>();
		stack.push(10);
		stack.push(11);
		stack.push(12);
		System.out.println(stack.pop());
	}
}