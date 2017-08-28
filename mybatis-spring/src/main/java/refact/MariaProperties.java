package refact;

public class MariaProperties extends java.util.Properties {
	java.util.Properties prop = new java.util.Properties();
    
	public MariaProperties() {
		prop.setProperty("driver", "org.mariadb.jdbc.Driver");
	    prop.setProperty("url", "jdbc:mariadb://localhost:3306/eng_db");
	    prop.setProperty("user", "eng");
	    prop.setProperty("password", "1234");
	}
	
	public java.util.Properties getProperties() {
		return this.prop;
	}
	
}
