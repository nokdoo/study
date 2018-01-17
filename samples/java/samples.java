//File to URL
public URL FtU(File file){
	String fileUrlString = file.toURI().toString();

	//빼도 될듯
    fileUrlString = fileUrlString.replaceAll("!/", "%21/");
    
	return new URL(fileUrlString);
}
