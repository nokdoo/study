package effective.item1.p7;

public class Main {

	public static void main(String args[]){
		Subclass subc = (Subclass) Interface.method();
		System.out.println(subc.c);
	}
}
