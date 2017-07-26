package c1;

import java.sql.SQLException;

public class TestMain1 {

	public static void main(String[] args) throws ClassNotFoundException, SQLException {
		UserDao1 ud = new UserDao1();
		ud.get();
	}

}
