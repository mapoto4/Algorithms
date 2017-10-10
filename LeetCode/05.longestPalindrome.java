public class Solution {
 public String longestPalindrome(String s) {
    		int Len = s.length();
		int maxLen = 1;
		int start = 0;

		if (Len == 1) {
			return s;
		}

		for (int i = 0; i < Len; i++) {

			int left = i - 1;
			int right = i + 1;
			while (left >= 0 && right < Len && s.charAt(left) == s.charAt(right)) {
				if (right - left + 1 > maxLen) {
					maxLen = right - left + 1;
					start = left;

				}
				left--;
				right++;
			}
		}

		for (int i = 0; i < Len; i++) {
			int left = i;
			int right = i + 1;
			while (left >= 0 && right < Len && s.charAt(left) == s.charAt(right)) {
				if (right - left + 1 > maxLen) {
					maxLen = right - left + 1;
					start = left;
				}
				left--;
				right++;
			}
		}
		return s.substring(start, start + maxLen);
	
    }
}

/*
 *解题思路：
 *1.回文分为单字符和双字符 
 *2.单字符取一点为中心，定义两个变量左右同时扫描
 *3.双字符采用中心点和中心点后一位为起点，定义两个变量从两个中点左右同时扫描 
 *4.当有一个扫描点遇到边界，或者两点不同，记录两点距离和最大距离做对比 ，取较大的值，记录左端点
 *5.返回左端点到右端点的字符
 * */