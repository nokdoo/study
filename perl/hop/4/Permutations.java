import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class Permutations {
	
	static <E> void Permute(List<E> items, List<E> perms) {
		if ( items.isEmpty() ) {
			Print(perms);
		}else {
			for ( int i=0; i<items.size(); i++ ) {
				List<E> newItems = new LinkedList<E>(items);
				List<E> newPerms = new LinkedList<E>(perms);
				newPerms.add(0, newItems.get(i));
				newItems.remove(i);
				Permute(newItems, newPerms);
			}
		}
    }
	
	static <E> void Print(List<E> items) {
		for (E e : items) {
			System.out.print(e+" ");
		}
		System.out.println();
	}
	
	public static void main(String args[]) {
		List<String> list = new ArrayList<String>(
					Arrays.asList("1", "2", "3", "4"));
		Permute(list, new LinkedList<String>());
	}
}

