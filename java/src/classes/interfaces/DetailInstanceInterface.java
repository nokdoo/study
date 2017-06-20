package classes.interfaces;

public class DetailInstanceInterface implements InstanceInterface {

	DetailInstanceInterface(){};
	
	public static InstanceInterface ii(){
		InstanceInterface ii = new DetailInstanceInterface();
		return ii;
	}
	
	@Override
	public void instanceInterface() {
		// TODO Auto-generated method stub
		
	}
}
