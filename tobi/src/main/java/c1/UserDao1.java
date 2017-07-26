package c1;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class UserDao1 {
	public void get() throws ClassNotFoundException, SQLException{
		
		Class.forName("org.mariadb.jdbc.Driver");
		Connection c = DriverManager.getConnection(
				"jdbc:mariadb://192.168.35.155:3306/eng_db",
				"eng",
				"1234"
				);
		PreparedStatement ps = c.prepareStatement(
				"select word from words"
				);
		ResultSet rs = ps.executeQuery();
		while(rs.next()){
			System.out.println(rs.getString("word"));
		}
	}
}
