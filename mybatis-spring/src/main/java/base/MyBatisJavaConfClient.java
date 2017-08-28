package base;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Properties;
import javax.sql.DataSource;
import org.apache.ibatis.mapping.Environment;
import org.apache.ibatis.session.Configuration;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.apache.ibatis.transaction.TransactionFactory;
import org.apache.ibatis.transaction.jdbc.JdbcTransactionFactory;

public class MyBatisJavaConfClient {

    private static SqlSessionFactory sesFact = null;

    public static void asd(String[] args) throws IOException {

        Properties prop = new Properties();
        prop.setProperty("driver", "org.mariadb.jdbc.Driver");
        prop.setProperty("url", "jdbc:mariadb://localhost:3306/eng_db");
        prop.setProperty("user", "eng");
        prop.setProperty("password", "1234");
        
        MyDataSourceFactory mdsf = new MyDataSourceFactory();
        mdsf.setProperties(prop);
        DataSource ds = mdsf.getDataSource();
        
        TransactionFactory trFact = new JdbcTransactionFactory();
        Environment environment = new Environment("development", trFact, ds);
        Configuration config = new Configuration(environment);
        config.addMapper(MyMapper.class);
        
        sesFact = new SqlSessionFactoryBuilder().build(config);

        try (SqlSession session = sesFact.openSession()) {
            
        	List<String> numOfBooks = session.selectList("getWords");
        	for (String string : numOfBooks) {
				System.out.println(string);
			}
            //int numOfBooks = session.selectOne("getNumberOfBooks");
            //System.out.format("There are %d books", numOfBooks);
        }
    }
}