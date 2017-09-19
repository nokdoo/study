package base;

import java.util.Properties;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class BeanFactory {
	
	@Bean
	public MyDataSourceFactory myDataSourceFactory(){
		return new MyDataSourceFactory();
	}
	
	@Bean
	public Properties mariaDBProperties(){
		return new Properties();
	}
	
	@Bean
	public Properties properties(){
		
		return null;
	}

}
