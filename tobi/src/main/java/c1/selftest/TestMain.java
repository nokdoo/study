package c1.selftest;

import java.sql.SQLException;

import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class TestMain {

	public static void main(String[] args) throws ClassNotFoundException, SQLException {
		ApplicationContext contect 
		= new AnnotationConfigApplicationContext(DaoFactory.class);
		UserDao dao = contect.getBean("userDao", UserDao.class);
		
		dao.get();
		
		String a = "abc";
		String b = new String("abc");
		System.out.println(a.equals(b));
		System.out.println(a == b);
		
	}
}
