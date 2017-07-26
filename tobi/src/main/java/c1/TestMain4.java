package c1;

import java.sql.SQLException;

public class TestMain4 {

	public static void main(String[] args) throws ClassNotFoundException, SQLException {
		ConnectionMaker connectionMaker = new DConnectionMaker();
		UserDao4 ud4 = new UserDao4(connectionMaker);
		ud4.get();
	}
		
}
