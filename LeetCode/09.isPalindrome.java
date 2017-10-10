public class Solution {
    public boolean isPalindrome(int x) {
		if (x >= 2147483647 || x <= -2147483648)
			return false;
		if(x<0)
			return false;
		if(x<10)
			return true;
		

		int result = 0;
		int result2 =x;
		
		while (x > 0) {	
			if (result != 0 && Integer.MAX_VALUE / result < 10  && Integer.MAX_VALUE / result > -10)  
	             return false; 
			
			result = result * 10 + x%10;
			x = x / 10;
		}
		return result==result2;
    }
}
/*解题思路：
 *1. 初开始认为将整数最大位和最小位比较，左右两个点同时移动。
 *2. 后将整数逆转与原数比较
 */
	   