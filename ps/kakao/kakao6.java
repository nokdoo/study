package test;

import java.util.LinkedList;

class Loc{
	int i;
	int j;
	public Loc(int i, int j){
		this.i = i;
		this.j = j;
	}
}

public class kakao6 {
	public static void main(String args[]){
		kakao6 sol = new kakao6();
		System.out.println(sol.solv("CCBDE", "AAADE", "AAABF", "CCBBF"));
		System.out.println(sol.solv("TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"));
	}
	
	public int solv(String ... str){
		int m = str.length;
		int n = str[0].length();
		int result = 0;
		char map[][] = new char[m][n];
		for(int i=0; i<m; i++){
			map[i] = str[i].toCharArray();
		}
		
		LinkedList<Loc> loc = new LinkedList<Loc>();
		int flag = 0;
		
		for(int i=1; i<m; i++){
			for( int j=1; j<n; j++){
				if(check(i, j, map)){
					loc.add(new Loc(i, j));
					flag = 1;
				}
			}
		}
		
		for(int i=loc.size(); i>0; i--){
			Loc ij = loc.pop();
			map[ij.i][ij.j] = '0';
			map[ij.i-1][ij.j] = '0';
			map[ij.i][ij.j-1] = '0';
			map[ij.i-1][ij.j-1] = '0';
		}
		
		for(int j=0; j<n; j++){
			for(int i=m-1; i>=0; i--){
				if(map[i][j] == '0'){
					int k = i;
					i--;
					for(; i>=0 && k>=0; i--){
						if(map[i][j] != '0'){
							if(i!=k){
								map[k][j] = map[i][j];
								map[i][j] = '0';
								k--;
							}
						}
					}
				}
			}
		}
		
		if(flag == 1){
			String str2[] = new String[m];
			for(int i=0; i<m; i++){
				str2[i] = String.copyValueOf(map[i]);
			}
			result += solv(str2);
		}else{
			for(int i=0; i<m; i++){
				for(int j=0; j<n; j++){
					if(map[i][j] == '0'){
						result++;
					}
				}
			}
		}
		
		return result;
	}
	
	public boolean check(int i, int j, char map[][]){
		if(map[i][j] == '0') return false;
		if(map[i][j] == map[i-1][j-1] && map[i][j] == map[i-1][j] && map [i][j] == map[i][j-1]){
			return true;
		}
		return false;
	}
}
