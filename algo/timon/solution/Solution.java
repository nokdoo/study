package solution;

public class Solution {
	
	Rank[] rankList;
	int lengh_rankList;

	public Solution(Rank[] rankArray, int length) {
		this.rankList = rankArray;
		this.lengh_rankList = length;
	}
	
	public void getRank() {
		int low = 0; int high = lengh_rankList-1;
		
		//10시 정렬
		sort(rankList, low, high, "value1");
		for(int i=0; i<high; i++) {
			rankList[i].rank1 = i+1;
		}
		
		//11시 정렬
		sort(rankList, low, high, "value2");
		
		//rank2는 필요 없지만 편의성을 위해 추가
		/*for(int i=0; i<high; i++) {
			rankList[i].rank2 = i+1;
		}*/
	}

	private void sort(Rank[] rankList, int low, int high, String compare) {
		if(low < high) {
			int pi = partition(rankList, low, high, compare);
			sort(rankList, low, pi-1, compare);
			sort(rankList, pi+1, high, compare);
		}
	}

	private int partition(Rank[] rankList, int low, int high, String compare) {
		int pivot = 0;
		
		if(compare.equals("value1")) {
			pivot = rankList[high].itemFormat.getValue_of_sales1();
		}else if(compare.equals("value2")) {
			pivot = rankList[high].itemFormat.getValue_of_sales2();
		}else {
			System.out.println("error : 인자가 부정확 합니다.");
			return 0;
		}
		
		int i = low-1;
		for(int j = low; j<high; j++) {
			int value_of_sales = 0;
			if(compare.equals("value1")) {
				value_of_sales = rankList[j].itemFormat.getValue_of_sales1();
			}else if(compare.equals("value2")) {
				value_of_sales = rankList[j].itemFormat.getValue_of_sales2();
			}
			if(value_of_sales > pivot) {
				i++;
				Rank tmp = rankList[i];
				rankList[i] = rankList[j];
				rankList[j] = tmp;
			}
		}
		Rank tmp = rankList[i+1];
		rankList[i+1] =rankList[high];
		rankList[high] = tmp;
		return i+1;
	}
	

}
