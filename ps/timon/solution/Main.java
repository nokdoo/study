package solution;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.text.NumberFormat;
import java.util.Locale;

public class Main {
	public static void main(String args[]) {
		
		//argument
		//run configurations -> arguments = C:\Users\nokdoot\Desktop\2017_be_sheet.csv
		String csvFile = args[0];
        BufferedReader br = null;
        String line = "";
        int idx = 0;
        
        Rank rankArray[] = new Rank[100];
        
        try {
            br = new BufferedReader(new FileReader(csvFile));
            while ((line = br.readLine()) != null) {
            	//# 따옴표 delimeter
            	String[] format = line.split(",(?=(?:[^\"]*\"[^\"]*\")*[^\"]*$)");
            	
            	ItemFormat item_format = new ItemFormat();
            	item_format.setItem_name(format[0]);
            	item_format.setCost1(Integer.parseInt(format[1]));
            	item_format.setCost2(Integer.parseInt(format[2]));
            	item_format.setCnt_of_sales1(Integer.parseInt(format[3]));
            	item_format.setCnt_of_sales2(Integer.parseInt(format[4]));
            	item_format.setValue_of_sales1();
            	item_format.setValue_of_sales2();
            	Rank rank = new Rank();
            	rank.itemFormat = item_format;
            	
            	rankArray[idx] = rank;
            	idx++;
            }

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (br != null) {
                try {
                    br.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
        
        Solution sol = new Solution(rankArray, idx);
        sol.getRank();
        
        int cnt_list = 3; // 3�� ���
        for(int i=0; i<cnt_list; i++) {
        	//������
        	System.out.println("���� ���� || ���� ���� || ��ǰ�� || �ǸŰ� || ���� || ������");
        	int discount = (int) ((float)((rankArray[i].itemFormat.getCost2() - rankArray[i].itemFormat.getCost1())) / (float)(rankArray[i].itemFormat.getCost2()) * 100);
        	System.out.println((i+1) + "    " + ((i+1) - rankArray[i].rank1) + "    " + rankArray[i].itemFormat.getItem_name() + "    " + NumberFormat.getNumberInstance(Locale.US).format(rankArray[i].itemFormat.getCost1()) + "    " + NumberFormat.getNumberInstance(Locale.US).format(rankArray[i].itemFormat.getCost2()) + "    " + discount + "%");
        }
        
        System.exit(0); 
	}
}
