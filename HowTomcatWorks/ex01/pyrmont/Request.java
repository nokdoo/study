package ex01.pyrmont;

import java.io.InputStream;
import java.io.IOException;
import java.*;

public class Request {

  private InputStream input;
  private String uri;
  public String contentType;

  public Request(InputStream input) {
    this.input = input;
  }

  public void parse() {
    // Read a set of characters from the socket
    StringBuffer request = new StringBuffer(2048);
	String requestStr = null;
    int i;
    byte[] buffer = new byte[2048];
    try {
      i = input.read(buffer);
    }
    catch (IOException e) {
      e.printStackTrace();
      i = -1;
    }
    for (int j=0; j<i; j++) {
      request.append((char) buffer[j]);
    }
	requestStr = request.toString();
	String[] lines = requestStr.split("\r\n");
	for(String line : lines){
		if(line.startsWith("Accept:")){
			contentType = getType(line);
		}
	}
	
    System.out.print(requestStr);
    uri = parseUri(requestStr);
  }

  private String getType(String line){
    String[] types = line.substring(8).split(",");
	return types[0];
  }

  private String parseUri(String requestString) {
    int index1, index2;
    index1 = requestString.indexOf(' ');
    if (index1 != -1) {
      index2 = requestString.indexOf(' ', index1 + 1);
      if (index2 > index1)
        return requestString.substring(index1 + 1, index2);
    }
    return null;
  }

  public String getUri() {
    return uri;
  }

}
