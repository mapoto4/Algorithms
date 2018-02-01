package pat;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class B_1002 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String N = input.next();

		char[] ch = N.toCharArray();

		int sum = 0;
		for (char i : ch) {
			sum = sum + Integer.parseInt(String.valueOf(i));
		}
		Map<Character, String> mp = new HashMap<>();
		mp.put('1', "yi");
		mp.put('2', "er");
		mp.put('3', "san");
		mp.put('4', "si");
		mp.put('5', "wu");
		mp.put('6', "liu");
		mp.put('7', "qi");
		mp.put('8', "ba");
		mp.put('9', "jiu");
		mp.put('0', "ling");

		String s = String.valueOf(sum);
		char[] c = s.toCharArray();
		String result = mp.get(c[0]);
		
		for (int i = 1; i < c.length; i++) {
			result =result + " "+ mp.get(c[i]);

		}
		System.out.print(result);

	}

}
