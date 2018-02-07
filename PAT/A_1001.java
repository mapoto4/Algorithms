package pat;

import java.text.DecimalFormat;
import java.util.Scanner;

public class A_1001 {

	public static void main(String[] args) {
		int a = 0;
		int b = 0;
		int sum = 0;
		Scanner input = new Scanner(System.in);
		a = input.nextInt();
		b = input.nextInt();
		sum = a + b;
		
		DecimalFormat df = new DecimalFormat("#,###");
		System.out.print(df.format(sum));
	}

}
