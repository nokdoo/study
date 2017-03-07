package c3;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Path;

public class CheckSum {

	public static void main(String[] arg) {
		FileReader fr = null;
		try {
			fr = new FileReader("/home/nokdoo/study/jcook/src/main/java/c3/CheckSum.txt");
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		BufferedReader br = new BufferedReader(fr);
		int a = process(br);
		System.getProperty("user.dir");
		System.out.println(System.getProperty("line.separator"));
		System.out.println(a);
	}

	public static int process(BufferedReader is) {
		int sum = 0;
		try {
			String inputLine;
			while ((inputLine = is.readLine()) != null) {
				int i;
				for (i = 0; i < inputLine.length(); i++) {
					System.out.print(inputLine.charAt(i));
					sum += inputLine.charAt(i);
				}
				System.out.println();
			}
		} catch (IOException e) {
			throw new RuntimeException("IOException: " + e);
		}
		return sum;
	}

}