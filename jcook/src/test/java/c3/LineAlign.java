package c3;

public class LineAlign {

	private int lineWidth = 0;

	public enum AlignAttr{
		LEFT, CENTER, RIGHT
	}
	public AlignAttr align;
	
	public LineAlign(int pageWidth, AlignAttr align){
		this.lineWidth = pageWidth;
		this.align = align;
	}
	
	public String Write(String content){
		return SetFormat(content);
	}
	
	private void pad(StringBuilder to, int len){
		for(int i = 0; i<len; i++){
			to.append(' ');
		}
	}
	
	public String SetFormat(String content){
		StringBuilder sb = new StringBuilder("|");
		int len = content.length();
		switch (align) {
		case LEFT:
			sb.append(content);
			pad(sb, lineWidth-len);
			break;
		case CENTER:
			int haha = (lineWidth-len);
			pad(sb, haha/2);
			sb.append(content);
			pad(sb, haha-haha/2);
			break;
		case RIGHT:
			pad(sb, lineWidth-len);
			sb.append(content);
			break;

		default:
			break;
		}
		sb.append("|");
		return sb.toString();
	}
	
}
