package c1.selftest;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class DaoFactory {
	
	@Bean
	public ConnectionMaker connectionMaker(){
		DConnectionMaker dcm = new DConnectionMaker();
		System.out.println(dcm);
		return dcm;
	}
	
	@Bean
	public UserDao userDao(){
		return new UserDao(connectionMaker());
	}
	
	@Bean
	public UserDao testBean(){
		return new UserDao(connectionMaker());
	}
	
}
