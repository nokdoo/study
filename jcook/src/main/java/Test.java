import java.util.StringTokenizer;

public class Test {

	public static void main(String[] args) {

		StringBuffer sb = new StringBuffer(10);
		tet(sb);
		System.out.println(sb);
	}
	
	public static void tet(StringBuffer sb){
		sb.append('a');
	}

}
