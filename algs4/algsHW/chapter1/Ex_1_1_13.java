package algs4.algsHW.chapter1;

public class Ex_1_1_13 {

	public static void reverse(int[][] a) {
		for(int i = 0;i<a[0].length;i++) {
			System.out.println();
			for(int j = 0;j<a.length;j++) {
				System.out.printf("%4d",a[j][i]);
			}
			
		}
	}
	
	public static void main(String[] args) {
		int[][] a = {{1,2,3},{4,5,6}};
		reverse(a);
	}

}
