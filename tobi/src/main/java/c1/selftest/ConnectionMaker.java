package c1.selftest;

import java.sql.SQLException;

public interface ConnectionMaker {

	public java.sql.Connection Connection() throws SQLException, ClassNotFoundException;

}
