import java.util.Arrays;
import java.util.List;
import java.util.Optional;
import static java.util.stream.Collectors.toList;
import static java.util.stream.Collectors.joining;
import static java.util.Comparator.comparing;

public class TnT
{
	public static void main(String[] args)
	{
		Trader raoul = new Trader("Raoul", "Cambridge");
		Trader mario = new Trader("Mario", "Milan");
		Trader alan = new Trader("Alan", "Cambridge");
		Trader brian = new Trader("Brian", "Cambridge");

		List<Transaction> transactions = Arrays.asList(
			new Transaction(brian, 2011, 300),
			new Transaction(raoul, 2012, 1000),
			new Transaction(raoul, 2011, 400),
			new Transaction(mario, 2012, 710),
			new Transaction(mario, 2012, 700),
			new Transaction(alan, 2012, 950)
		);

		List<Transaction> result = transactions.stream()
												.filter(a -> a.getYear() == 2011)
												.sorted(comparing(Transaction::getValue))
												.collect(toList());
		
		for(Transaction t : result)
		{
			System.out.println(t.getTrader()+" "+t.getYear()+" "+t.getValue());
		}
		System.out.println();
		System.out.println();

		List<String> result2 = transactions.stream()
												.map(a->a.getTrader().getCity())
												.distinct()
												.collect(toList());
		for(String t : result2)
		{
			System.out.println(t);
		}
		System.out.println();
		System.out.println();
		
		List<Trader> result3 = transactions.stream()
											.map(Transaction::getTrader)
											.filter(t->t.getCity().equals("Cambridge"))
											.distinct()
											.sorted(comparing(Trader::getName))
											.collect(toList());
		for(Trader t : result3)
		{
			System.out.println(t.getName());
		}
		System.out.println();
		System.out.println();

		String result4 = transactions.stream()
											.map(t->t.getTrader().getName())
											.distinct()
											.sorted()
											.collect(joining());
		System.out.println(result4);
		System.out.println();
		System.out.println();

		Boolean result5 = transactions.stream()
										.anyMatch(t->t.getTrader().getCity().equals("Milan"));
		System.out.println(result5);
		System.out.println();
		System.out.println();
		

		List<Integer> result6 = transactions.stream()
												.filter(t->t.getTrader().getCity().equals("Cambridge"))
												.map(Transaction::getValue)
												.collect(toList());
		for(Integer t : result6)
		{
			System.out.println(t);
		}
		System.out.println();
		System.out.println();

		Optional<Integer> result7 = transactions.stream()
										.map(Transaction::getValue)
										.reduce(Integer::max);

		System.out.println(result7);
		System.out.println();
		System.out.println();

		Optional<Integer> result8 = transactions.stream()
										.map(Transaction::getValue)
										.reduce(Integer::min);

		System.out.println(result8);
	}

}
