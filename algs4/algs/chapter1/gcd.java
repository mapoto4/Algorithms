package algs4.algs.chapter1;

import java.util.Scanner;

public class gcd {

	public static int gcds (int a ,int b) {
		if(b==0) return a;
		int r = a % b;
		return gcds(b,r);
	}
	
	@SuppressWarnings("resource")
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		
		int a = in.nextInt();
		int b = in.nextInt();
		
		int wq = gcds(a,b);
		
		System.out.println(wq);
	}
	
	
}
