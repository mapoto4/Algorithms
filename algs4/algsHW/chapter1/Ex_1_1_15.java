package algs4.algsHW.chapter1;

public class Ex_1_1_15 {

	public static int[] histogram(int[] a, int M) {
		int[] result = new int[M];
		for (int i = 0; i < a.length; i++) {
			if (a[i] >= 0 && a[i] < M) {
				result[a[i]]++;
			}
		}

		return result;
	}

	public static void main(String[] args) {
		
		int[] a = {1,2,3,4,5,3,2,1};
		int[] result = histogram(a,5);
		for(int i = 0;i<result.length;i++) {
			System.out.printf("%2d",result[i]);
		}
	}

}
