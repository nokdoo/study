package c1.datasource;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class UserDao{
	private javax.sql.DataSource dataSource;
	
	public void setDataSource(javax.sql.DataSource dataSource){
		this.dataSource = dataSource;
	}
	
	public void get() throws ClassNotFoundException, SQLException{
		
		
		Connection c = dataSource.getConnection();
		
		PreparedStatement ps = c.prepareStatement(
				"select word from words"
				);
		ResultSet rs = ps.executeQuery();
		while(rs.next()){
			System.out.println(rs.getString("word"));
		}
	}

}
