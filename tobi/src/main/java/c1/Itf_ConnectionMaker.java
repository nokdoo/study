package c1;

import java.sql.SQLException;

public interface Itf_ConnectionMaker {
	java.sql.Connection Connection() throws ClassNotFoundException, SQLException;
}
