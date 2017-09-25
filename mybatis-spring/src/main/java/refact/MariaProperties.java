package refact;

import java.util.Properties;

public class MariaProperties extends Properties{

	public Properties getProperties() {
		Properties prop = new Properties();
        prop.setProperty("driver", "org.mariadb.jdbc.Driver");
        prop.setProperty("url", "jdbc:mariadb://192.168.35.155:3306/eng_db");
        prop.setProperty("user", "eng");
        prop.setProperty("password", "1234");
        return prop;
	}
	
	
}