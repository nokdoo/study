package solution;

public class ItemFormat{
	private String item_name;
	private int cost1;
	private int cost2;

	private int cnt_of_sales1;
	private int value_of_sales1;
	
	private int cnt_of_sales2;
	private int value_of_sales2;
	
	public int getValue_of_sales1() {
		return value_of_sales1;
	}

	public void setValue_of_sales1() {
		this.value_of_sales1 = cost1 * cnt_of_sales1;
	}

	public int getValue_of_sales2() {
		return value_of_sales2;
	}

	public void setValue_of_sales2() {
		this.value_of_sales2 = cost1 * cnt_of_sales2;
	}

	public String getItem_name() {
		return item_name;
	}
	public void setItem_name(String item_name) {
		this.item_name = item_name;
	}
	public int getCost1() {
		return cost1;
	}
	public void setCost1(int cost1) {
		this.cost1 = cost1;
	}
	public int getCost2() {
		return cost2;
	}
	public void setCost2(int cost2) {
		this.cost2 = cost2;
	}
	public int getCnt_of_sales1() {
		return cnt_of_sales1;
	}
	public void setCnt_of_sales1(int cnt_of_sales1) {
		this.cnt_of_sales1 = cnt_of_sales1;
	}
	public int getCnt_of_sales2() {
		return cnt_of_sales2;
	}
	public void setCnt_of_sales2(int cnt_of_sales2) {
		this.cnt_of_sales2 = cnt_of_sales2;
	}

	public void calculateValue1() {
		this.value_of_sales1 = cnt_of_sales1 * cost1;
	}

	public void calculateValue2() {
		this.value_of_sales2 = cnt_of_sales1 * cost2;
	}
}
