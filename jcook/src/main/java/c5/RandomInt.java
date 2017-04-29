package c5;

import java.util.Random;

public class RandomInt {
	public static void main(String[] a) {
		Random r = new Random();
		for (int i = 0; i < 10; i++)
			// nextInt(10) goes from 0-9; add 1 for 1-10;
			System.out.println(1 + r.nextInt(10));
		System.out.println(r.nextDouble());
		System.out.println(r.nextInt());
	}
}