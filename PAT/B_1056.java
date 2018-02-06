import java.util.Scanner;

public class B_1056 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int N = input.nextInt();
		
		int[] num = new int[N];
		for(int i = 0 ;i< N;i++ ){
			num[i] = input.nextInt();
		}

 		int sum = 0 ;
		for(int i = 0;i<N;i++){
			for(int j = i+1;j<N;j++){
				int x = num[i]+num[j]*10;
				int y = num[j]+num[i]*10;
				sum = sum + x +y;
			}
		}
		System.out.print(sum);
	}

}