package refact;

import java.io.IOException;
import java.util.List;
import javax.sql.DataSource;
import org.apache.ibatis.mapping.Environment;
import org.apache.ibatis.session.Configuration;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.apache.ibatis.transaction.TransactionFactory;
import org.apache.ibatis.transaction.jdbc.JdbcTransactionFactory;

public class Main {

    private static SqlSessionFactory sesFact = null;

    public static void main(String[] args) throws IOException {

        DataSource ds = new MyDataSourceFactory().getDataSource();
        
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