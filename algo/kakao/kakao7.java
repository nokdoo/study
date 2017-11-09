import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

public class kakao7 {
	
	public static void main(String[] args) throws ParseException {
		kakao7 sol = new kakao7();
		int result = 0;
		result = sol.solution(new String[] {"2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s"});
		System.out.println(result);
		result = sol.solution(new String[] {"2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s"});
		System.out.println(result);
		result = sol.solution(new String[] {"2016-09-15 20:59:57.421 0.351s", 
				"2016-09-15 20:59:58.233 1.181s", 				"2016-09-15 20:59:58.299 0.8s", 				
				"2016-09-15 20:59:58.688 1.041s", 				"2016-09-15 20:59:59.591 1.412s", 
				"2016-09-15 21:00:00.464 1.466s", 				"2016-09-15 21:00:00.741 1.581s", 
				"2016-09-15 21:00:00.748 2.31s", 				"2016-09-15 21:00:00.966 0.381s", 
				"2016-09-15 21:00:02.066 2.62s"});
		System.out.println(result);
	}
	
	public int solution(String str[]) throws ParseException {
		int cnt = str.length;
		
		Traffic traffic[] = new Traffic[cnt];
		int i = 0;
		for(String s : str) {
			traffic[i] = new Traffic();
			int idx = s.lastIndexOf(' ');
			String S = s.substring(0, idx);
			String T = s.substring(idx+1);
			int i_1 = T.indexOf('.');
			int i_2 = T.indexOf('s');
			int sec = 0;
			int millisec = 0;
			if(i_1 >= 0) {
				sec = Integer.parseInt(T.substring(0, i_1));
				millisec = Integer.parseInt(T.substring(i_1+1, i_2));
			}else {
				sec = Integer.parseInt(T.substring(0, T.indexOf('s')));
			}
			SimpleDateFormat sdf = new SimpleDateFormat("YYYY-MM-DD HH:mm:ss.SSS");
			Date end_date = sdf.parse(S);
			Calendar cal = Calendar.getInstance();
			cal.setTime(end_date);
			cal.add(Calendar.SECOND, -sec);
			cal.add(Calendar.MILLISECOND, -(millisec-1));
			Date start_date = cal.getTime();
			traffic[i].end_date = end_date;
			traffic[i].start_date = start_date;
			i++;
		}
		
		int max_cnt = 0;
		for(i = 0; i<cnt; i++) {
			int max_tmp1 = 0;
			int max_tmp2 = 0;
			for(int j=0; j<cnt; j++) {
				max_tmp1 += scan(traffic[i].end_date, traffic[j], -1);
				max_tmp2 += scan(traffic[i].end_date, traffic[j], 1);
			}
			max_cnt = Math.max(max_cnt, Math.max(max_tmp1, max_tmp2));
			
		}
		return max_cnt;
	}

	private int scan(Date end_date, Traffic traffic2, int i) {
		Calendar cal = Calendar.getInstance();
		cal.setTime(end_date);
		cal.add(Calendar.SECOND, i);
		Date date = cal.getTime();
		if(i>0) { // end_date <= ... < date
			if((end_date.compareTo(traffic2.start_date) <= 0 && traffic2.start_date.compareTo(date) < 0)
					|| (end_date.compareTo(traffic2.end_date) <= 0 && traffic2.start_date.compareTo(date) < 0)) {
				return 1;
			}
		}else { // date <  ... <= end_date
			if((date.compareTo(traffic2.start_date) < 0 && traffic2.start_date.compareTo(end_date) <= 0)
					|| (date.compareTo(traffic2.end_date) < 0 && traffic2.start_date.compareTo(end_date) <= 0)) {
				return 1;
			}
		}
		return 0;
	}
	
}


class Traffic{
	Date start_date;
	Date end_date;
}
