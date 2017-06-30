package c7;

public class MyStack<T>{
	private int depth = 0;
	public static final int DEFAULT_INITIAL = 10;
	private T[] stack;
	private int length;
	
	public MyStack(int howBig){
		if(howBig <= 0){
			throw new IllegalArgumentException("0보다 큰 숫자 입력.");
		}
		length = howBig;
		stack = (T[]) new Object[length];
		
	}
	
	public MyStack(){
		this(DEFAULT_INITIAL);
	}
	
	public boolean isEmpty(){
		return depth == 0;
	}
	
	public void push(T obj){
		if(depth>=length){
			throw new IllegalAccessError("스택이 이미 가득 찼습니다.");
		}
		stack[depth++] = obj;
	}
	
	public T pop(){
		return stack[--depth];
	}
	
}