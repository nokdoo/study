class Vehicle{
	int passengers;
	int fuelcap;
	int mpg;

	//public Vehicle(int p, int f, int m){
//		passengers = p;
//		fuelcap = f;
//		mpg = m;
//	}

	int range(){
		return mpg * fuelcap;
	}

	double fuelneeded(int miles){
		return (double) miles/mpg;
	}

}
