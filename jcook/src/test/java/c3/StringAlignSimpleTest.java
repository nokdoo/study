package c3;


public class StringAlignSimpleTest {

	public static void main(String[] agrv){
		
		LineAlign la = new LineAlign(10, LineAlign.AlignAttr.CENTER);
		
		System.out.println(la.Write("haha"));

	}
	
}
