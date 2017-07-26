package c1;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class UserDao3 {
	private c1.ConnectionMaker con;
	
	public UserDao3(){
		con = new c1.DConnectionMaker();
	}
	
	public void get() throws ClassNotFoundException, SQLException{
		
		
		Connection c = con.Connection();
		
		PreparedStatement ps = c.prepareStatement(
				"select word from words"
				);
		ResultSet rs = ps.executeQuery();
		while(rs.next()){
			System.out.println(rs.getString("word"));
		}
	}
	
}
