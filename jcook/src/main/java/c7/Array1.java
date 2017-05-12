package c7;

import java.util.Calendar;

public class Array1 {

	public static void main(String[] args) {
		final int MAX = 10;
		Calendar[] days = new Calendar[MAX];
		for(int i = 0; i < MAX; i ++){
			days[i] = Calendar.getInstance();
		}
		
		int[][] me = new int[10][];
		for(int i = 0; i< 10; i++){
			me[i] = new int[24];
		}
		
		System.out.println(me.length);
		System.out.println(me[0].length);
		
	}

}
