import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Calendar;

public class kakao4 {
	
	public static void main(String[] args) throws ParseException {
		
		kakao4 sol = new kakao4();
		System.out.println(sol.answer(1, 1, 5, new String[]{"08:00", "08:01", "08:02", "08:03"}));
		System.out.println(sol.answer(2, 10, 2, new String[]{"09:10", "09:09", "08:00"}));
		System.out.println(sol.answer(2, 1, 2, new String[]{"09:00", "09:00", "09:00", "09:00"}));
		System.out.println(sol.answer(1, 1, 5, new String[]{"00:01", "00:01", "00:01", "00:01", "00:01"}));
		System.out.println(sol.answer(1, 1, 1, new String[]{"23:59"}));
		System.out.println(sol.answer(10, 60, 45, new String[]{"23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"}));
	}
	
	
	public String answer(int n, int t, int m, String timeable[]) throws ParseException {
		Arrays.sort(timeable);
		int i = 0;
		String busTime = "09:00";
		String lateTime = addMin(timeable[i], -1);
		int stackCrew = 0;
		String cur_Time = "";
		
		
		//#String to Date
		//#Add minute
		while(true) {
			if(i==timeable.length) break;
			if(n == 0) break;
			
			int busCap = m;
			
			while(i < timeable.length && busCap> 0 && (cur_Time = timeable[i]).compareTo(busTime) <= 0) {
				stackCrew++;
				busCap--;
				i++;
			}
			stackCrew = stackCrew-m;
			n--;
			
			if(stackCrew <= -1) {
				lateTime = busTime;
			}else if(busCap == 0) {
				lateTime = addMin(cur_Time, -1);
			}
			busTime = addMin(busTime, t);
			
			stackCrew = Math.max(stackCrew, 0);
			
		}
		
		return lateTime;
	}
	
	//#String to Date
	//#Add minute
	public String addMin(String time, int i) throws ParseException {
		SimpleDateFormat sdf = new SimpleDateFormat("HH:mm");
		java.util.Date d = sdf.parse(time);
		Calendar cal = Calendar.getInstance();
		cal.setTime(d);
		cal.add(Calendar.MINUTE, i);
		d = cal.getTime();
		return sdf.format(d);
	}
	
}
