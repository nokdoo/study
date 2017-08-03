package c1.selftest;

import java.sql.DriverManager;
import java.sql.SQLException;

public class DConnectionMaker implements ConnectionMaker {

	@Override
	public java.sql.Connection Connection() throws ClassNotFoundException, SQLException {
		Class.forName("org.mariadb.jdbc.Driver");
		java.sql.Connection c = DriverManager.getConnection(
				"jdbc:mariadb://192.168.35.155:3306/eng_db",
				"eng",
				"1234"
				);
		return c;
	}

}
