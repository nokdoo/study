import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class Q11052{
	public static void main(String[] args) throws NumberFormatException, IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine().trim());
		String[] values = br.readLine().trim().split(" ");
		
		Card[] cards = new Card[n];
		for(int i = 0; i<n; i++){
			cards[i] = new Card(Integer.parseInt(values[i]), i+1);
		}
		
		cards = Arrays.stream(cards)
			.sorted(Comparator.comparing(Card::getRate).reversed())
			.toArray(Card[]::new);
		
		int answer = Solution(cards, n);
		System.out.println(answer);
	}

	public static int Solution(Card[] cards, int n) {
		int answer = 0;
		for(int i = 0; i<cards.length; i++) {
			int multiple = n/cards[i].getCount();
			n = n-multiple*cards[i].getCount();
			answer += multiple*cards[i].getValue();
			if(n==0) {
				break;
			}
		}
		return answer;
	}
}

class Card{
	int value;
	double rate;
	int count;
	
	public Card(int value, int count){
		this.value = value;
		this.count = count;
		this.rate = value/count;
	}
	
	public double getRate(){
		return this.rate;
	}
	
	public int getValue() {
		return this.value;
	}
	
	public int getCount() {
		return this.count;
	}
}