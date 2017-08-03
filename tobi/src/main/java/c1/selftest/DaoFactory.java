package c1.selftest;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class DaoFactory {
	@Bean
	public ConnectionMaker connectionMaker(){
		return new DConnectionMaker();
	}
	
	@Bean
	public UserDao userDAO(){
		return new UserDao(connectionMaker());
	}
	
}
