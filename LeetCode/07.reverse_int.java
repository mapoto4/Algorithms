public class Solution {
    public int reverse(int x) {
		if (x >= 2147483647 || x <= -2147483648)
			return 0;

		int flag = 1;
		if (x >= 0) {
			flag = 1;
		} else {
			flag = -1;
			x = -x;
		}
		int result = 0;
		while (x > 0) {	
			if (result != 0 && Integer.MAX_VALUE / result < 10  && Integer.MAX_VALUE / result > -10)  
	             return 0; 
			
			result = result * 10 + x%10;
			x = x / 10;
		}
		return result * flag;
    }
}
/* 解题思路：
 * 1.检查正负数
 * 2.通过循环不断赋值给新变量
 * 遇到问题： 
 * 1.数据溢出
 * Java在int的取值边界十倍以内是归属于溢出 
 */