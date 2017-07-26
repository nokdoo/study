package c1;

import java.sql.DriverManager;
import java.sql.SQLException;

public interface ConnectionMaker {

	public java.sql.Connection Connection() throws SQLException, ClassNotFoundException;

}
