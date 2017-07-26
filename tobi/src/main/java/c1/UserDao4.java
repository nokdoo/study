package c1;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class UserDao4 implements Itf_ConnectionMaker{
	private ConnectionMaker con;
	
	public UserDao4(ConnectionMaker connectionMaker){
		this.con = connectionMaker;
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

	@Override
	public java.sql.Connection Connection() {
		// TODO Auto-generated method stub
		return null;
	}
	
}
