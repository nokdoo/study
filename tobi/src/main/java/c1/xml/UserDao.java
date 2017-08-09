package c1.xml;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class UserDao implements ConnectionMaker{
	private ConnectionMaker con;
	
	public UserDao(ConnectionMaker connectionMaker){
		this.con = connectionMaker;
	}
	
	public void setConnectionMaker(ConnectionMaker connectionMaker){
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
	public java.sql.Connection Connection() throws SQLException, ClassNotFoundException {
		// TODO Auto-generated method stub
		return null;
	}
	
}
