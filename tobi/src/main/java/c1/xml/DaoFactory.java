	package c1.xml;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class DaoFactory {
	@Bean
	public ConnectionMaker connectionMaker(){
		return new DConnectionMaker();
	}
	
	/*@Bean
	public UserDao userDao(){
		UserDao userDao = new UserDao();
		userDao.setConnectionMaker(connectionMaker());
		return userDao;
	}*/
	
	@Bean
	public UserDao userDao(){
		return new UserDao(connectionMaker());
	}
	
}
