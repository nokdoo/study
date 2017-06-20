package classes.returns;

public class OuterClass<T> {

	public static abstract class ReturnedClass{
		String t ;
		
		private ReturnedClass(){
			t = "test";
		}
		
		public T returnThis(){
			
			return (T) this;
		}
	}
	
	
	
	
}
