package algs4.algsHW.chapter1;

public class Ex_1_1_14 {

	public static int lg(int N) {
		int temp = 0;
		while (N != 0) {
			N = N >> 1;
			temp++;
		}

		return temp - 1;
	}

	public static void main(String[] args) {
		int N = 8;
		System.out.println(lg(N));
	}

}
