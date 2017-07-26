package c1;

import java.sql.SQLException;

public class TestMain2 {

	public static void main(String[] args) throws ClassNotFoundException, SQLException {
		UserDao2 ud2 = new Ext_UserDao2();
		ud2.get();
	}
		
}
