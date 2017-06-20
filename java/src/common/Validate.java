package common;

public final class Validate {
	private Validate(){}
	
	public static void isNull(Object o){
		if(o.equals(null)){
			throw new NullPointerException();
		}
	}
}
