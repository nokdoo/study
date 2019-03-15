import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;

public class BFS {

	public static void BFS(HashMap<String, Vertax> graph, String valueOfVertax) {
		Queue<String> queue = new LinkedList<String>();
		queue.add(valueOfVertax);
		graph.get(valueOfVertax).flag = true;

		while (!queue.isEmpty()) {
			valueOfVertax = queue.poll();
			System.out.print(valueOfVertax + " ");
			Vertax vertax = graph.get(valueOfVertax);
			Iterator<String> iter = vertax.next.iterator();
			while (iter.hasNext()) {
				String next_value = iter.next();
				if (graph.get(next_value).flag == false) {
					queue.add(next_value);
					graph.get(next_value).flag = true;
				}
			}
		}
	}

	public static void main(String[] args) throws Exception {
		HashMap<String, Vertax> graph = new HashMap<String, Vertax>();

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line;
		while ((line = br.readLine()) != null) {
			if (line.equals("DONE"))
				break;
			String[] tokens = line.split(" ");
			String valueOfVertax = tokens[0];
			Vertax vertax = new Vertax(valueOfVertax);
			graph.put(vertax.value, vertax);
			for (int i = 1; i < tokens.length; i++) {
				vertax.next.add(tokens[i]);
			}
		}
		BFS(graph, "A");
	}
}

class Vertax {
	String value;
	boolean flag;
	LinkedList<String> next;

	public Vertax(String value) {
		this.value = value;
		this.flag = false;
		next = new LinkedList<String>();
	}

}

/*
 * inputs on console of eclipse 
A B S
B A
C D E F S
D C
E C H
F C G
G S H
H E G
S A C G
DONE
 */

