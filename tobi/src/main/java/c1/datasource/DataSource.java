package c1.datasource;

import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Wrapper;

import javax.sql.CommonDataSource;

import org.springframework.jdbc.datasource.SimpleDriverDataSource;

public interface DataSource extends CommonDataSource, Wrapper{
	Connection getConnection() throws SQLException;
}
