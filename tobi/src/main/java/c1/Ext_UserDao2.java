package c1;

import java.sql.DriverManager;
import java.sql.SQLException;

public class Ext_UserDao2 extends UserDao2 {

	@Override
	java.sql.Connection Connection() throws SQLException, ClassNotFoundException {
		Class.forName("org.mariadb.jdbc.Driver");
		java.sql.Connection c = DriverManager.getConnection(
				"jdbc:mariadb://192.168.35.155:3306/eng_db",
				"eng",
				"1234"
				);
		return c;
	}

}
