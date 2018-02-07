package pat;

import java.util.Scanner;

public class B_1046 {

	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		int N = input.nextInt();

		int a = 0;
		int b = 0;
		
		int[] num = new int[N*4]; 
		for (int i = 0; i < N * 4; i++) {
			num[i] = input.nextInt();
		}
		
		for(int i = 0 ;i<N*4;i = i+4) {
			if(num[i+1] == num[i]+num[i+2]&&num[i+3] != num[i]+num[i+2]) {
				b++;
			}else if(num[i+1] != num[i]+num[i+2]&&num[i+3] == num[i]+num[i+2]) {
				a++;
			}
		}
		System.out.print(a+" "+b);
	}

}
