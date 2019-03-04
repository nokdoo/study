import java.io.BufferedReader;

public class B4963 {
	
	static int[] x = {-1, 0, 1, -1, 1, -1, 0, 1};
	static int[] y = {-1, -1, -1, 0, 0, 1, 1, 1};

	public static void followLand(int[][] map, int i, int j) {
		map[i][j] = 0;
		for ( int a=0; a<8; a++ ) {
			int next_i = i + y[a];
			int next_j = j + x[a];
			if ( 
					map.length <= next_i || 
					map[0].length <= next_j || 
					0 > next_i || 
					0 > next_j 
			) continue;
			
			if ( map[next_i][next_j] != 0 ) followLand(map, next_i, next_j);
		}
	}
	
	public static int solution(int[][] map, int w, int h) {
		int answer = 0;
		for ( int i=0; i<h; i++ ) {
			for ( int j=0; j<w; j++ ) {
				if ( map[i][j] == 0 ) continue;
				followLand(map, i, j);
				answer++;
			}
		}
		return answer;
	}

	public static void main(String[] args) {
		try ( BufferedReader br = new BufferedReader(new java.io.InputStreamReader(System.in))){
			
			String line;
			
			while ( ( line = br.readLine().trim() ) != null ) {
				String[] input = line.split(" ");
				int w = Integer.parseInt(input[0]);
				int h = Integer.parseInt(input[1]);
				
				if ( w == 0 && h == 0 ) break;
				
				int[][] map = new int[h][];
				for ( int i=0; i<h; i++) {
					int[] width = new int[w];
					
					String[] width_input = br.readLine().trim().split(" ");
					
					int idx = 0;
					for ( String str : width_input ) {
						width[idx++] = Integer.parseInt(str);
					}
					map[i] = width;
				}
				int answer = solution(map, w, h);
				System.out.println(answer);
			}
			
		}catch (Exception e) {
		}
		
	}

}
