package c8;

public class TestToString {

	public static void main(String[] args) {
		System.out.println(new TestToString());
	}
	
	
	public String toString(){
		return "sysout을 사용할 때, 해당 클래스의 toString이 있으면 대신 출력";
	}

}
