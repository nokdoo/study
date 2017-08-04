package c8;

public class CopyConstructorDemo {

	public static void main(String[] args) {
		CopyConstructorDemo obj1 = new CopyConstructorDemo(123, "hello");
		CopyConstructorDemo obj2 = new CopyConstructorDemo(obj1);
		if(!obj1.equals(obj2)){
			System.out.println("if");
		}
		System.out.println("done");
	}
	
	private int n;
	private String name;
	
	public CopyConstructorDemo(){
		
	}
	public CopyConstructorDemo(int n, String name){
		this.n = n;
		this.name = name;
	}
	
	public CopyConstructorDemo(CopyConstructorDemo obj){
		this.n = obj.n;
		this.name = obj.name;
	}

}
