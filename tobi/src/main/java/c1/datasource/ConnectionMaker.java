package c1.datasource;

import java.sql.SQLException;

public interface ConnectionMaker {

	public java.sql.Connection Connection() throws SQLException, ClassNotFoundException;

}
