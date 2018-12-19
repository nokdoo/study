import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    
    public static int solution(int n){
    	if(n==1) return 9;
        int[] map = new int[10];
        int[] tmp = new int[10];
        
        map[0] = 0;
        for(int i=1; i<10; i++){
            map[i] = 1;
        }
        
        for(int i=2; i<=n; i++){
            for(int j=0; j<10; j++){
                if(j==0){
                    tmp[j] = map[1];
                }else if(j==9){
                    tmp[j] = map[8];
                }else{
                    tmp[j] = map[j-1] + map[j+1];
                }                
                tmp[j] = tmp[j]%1_000_000_000;
            }
            System.arraycopy(tmp, 0, map, 0, 10);
        }
        
        int result = Arrays.stream(map).sum()%1_000_000_000;
        return result;
    }
    
    public static void Q10844(String[] args){
        int n = 0;
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))){
            n = Integer.parseInt(br.readLine().trim());
        }catch(IOException ioe){
            ;
        }
        int answer = solution(n);
        System.out.println(answer);
    }
}

