package c1.datasource;

import java.sql.SQLException;

import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.support.GenericXmlApplicationContext;

public class TestMain {

	public static void main(String[] args) throws ClassNotFoundException, SQLException {
		ApplicationContext context 
		= new GenericXmlApplicationContext("c1/datasource/applicationContext.xml");
		UserDao dao = context.getBean("userDao", UserDao.class);
		dao.get();
		
		String a = "abc";
		String b = new String("abc");
		System.out.println(a.equals(b));
		System.out.println(a == b);
		
	}
}
