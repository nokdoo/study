package c5;

public class InfinityCons {

	public static void main(String[] args){
		double d = 123;
		double e = 0;
		if(d/e == Double.POSITIVE_INFINITY)
			System.out.println("Check for POSITIVE_INFINITY works");
		double s = Math.sqrt(-1);
		if(s == Double.NaN)
			System.out.println("Comparison with NaN incorrectly retuns true");
		if(Double.isNaN(s))
			System.out.println("Double.isNaN() correctly returns true");
	}
}
