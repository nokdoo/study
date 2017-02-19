package c3;

public class StringBuilderDemo {
	public static void main(String[] argv) {
		String s1 = "Hello" + ", " + "World";
		System.out.println(s1);
		System.out.println(s1.hashCode());
		
		
		// Build a StringBuilder, and append some things to it.
		StringBuilder sb2 = new StringBuilder();
		sb2.append("Hello");
		sb2.append(',');
		sb2.append(' ');
		sb2.append("World");
		System.out.println(sb2.hashCode());
		
		
		// Get the StringBuilder's value as a String, and print it.
		String s2 = sb2.toString();
		System.out.println(s2);
		System.out.println(s2.hashCode());
		
		
		// Now do the above all over again, but in a more
		// concise (and typical "real-world" Java) fashion.
		System.out.println(new StringBuilder().append("Hello").append(',').append(' ').append("World"));
	}
}