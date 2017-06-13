class SeriesDemo{
	public static void main(String args[]){
		ByTwos ob = new ByTwos();

		for(int i=0; i<5; i++){
			System.out.println("Next value is " + ob.getNext());

		}

		System.out.println("\nResetting");

		for(int i=0; i<5; i++){
			System.out.println("Next value is " + ob.getNext());

		}	


	}
}
