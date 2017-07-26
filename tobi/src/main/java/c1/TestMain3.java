package c1;

import java.sql.SQLException;

public class TestMain3 {

	public static void main(String[] args) throws ClassNotFoundException, SQLException {
		UserDao3 ud3 = new UserDao3();
		ud3.get();
	}
		
}
