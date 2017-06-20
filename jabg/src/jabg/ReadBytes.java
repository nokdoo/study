package jabg;

import java.io.IOException;

public class ReadBytes {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		byte data[] = new byte[10];
		System.out.println("Enter some characters.");
		System.in.read(data);
		System.out.println("You entered: ");
		for(int i=0; i< data.length; i++){
			System.out.print((char) data[i]);
		}
		System.in.read(data);
		System.out.println("You entered: ");
		for(int i=0; i< data.length; i++){
			System.out.print((char) data[i]);
		}
	}

}
