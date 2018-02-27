package algs4.algsHW.chapter1;

import edu.princeton.cs.algs4.StdOut;

public class Ex_1_1_09 {

	public static void main(String[] args) {

		int N = 13;
		String s = "";
		for (int n = N; n > 0; n /= 2) 
			s = (n % 2) + s;
			StdOut.println(s);
	
						
		int M = 14;
		String result = Integer.toBinaryString(M);
		System.out.println(result);
			
		
		
		
		
		
		
	}

}
