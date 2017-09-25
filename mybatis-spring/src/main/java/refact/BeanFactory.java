package refact;

import java.util.Properties;

import javax.sql.DataSource;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class BeanFactory {
	
	@Bean
	public MyDataSourceFactory dataSourceFactory(){
		return new MyDataSourceFactory();
	}
	
	@Bean
	public DataSource dataSource(){
		MyDataSourceFactory dataSourceFactory = dataSourceFactory();
		dataSourceFactory.setProperties(mariaProperties());
		DataSource ds = dataSourceFactory.getDataSource();
		return ds;
	}
	
	@Bean
	public Properties mariaProperties(){
		Properties prop = new Properties();
		prop.setProperty("driver", "org.mariadb.jdbc.Driver");
        prop.setProperty("url", "jdbc:mariadb://192.168.35.155:3306/eng_db");
        prop.setProperty("user", "eng");
        prop.setProperty("password", "1234");
		return prop;
	}
	
}
