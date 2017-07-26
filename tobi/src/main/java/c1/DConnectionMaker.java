package c1;

import java.sql.DriverManager;
import java.sql.SQLException;

public class DConnectionMaker implements ConnectionMaker {

	@Override
	public java.sql.Connection Connection() throws ClassNotFoundException, SQLException {
		Class.forName("org.mariadb.jdbc.Driver");
		java.sql.Connection c = DriverManager.getConnection(
				);
		return c;
	}

}
