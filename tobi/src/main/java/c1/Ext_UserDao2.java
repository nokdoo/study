package c1;

import java.sql.DriverManager;
import java.sql.SQLException;

public class Ext_UserDao2 extends UserDao {

	@Override
	java.sql.Connection Connection() throws SQLException, ClassNotFoundException {
		Class.forName("org.mariadb.jdbc.Driver");
		java.sql.Connection c = DriverManager.getConnection(
				);
		return c;
	}

}
