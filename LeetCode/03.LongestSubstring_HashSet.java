public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int left=0;
		int right = 0;
		int maxLen=0;
		HashSet<Character>hs = new HashSet<Character>();
		while(right<s.length())
		{
			if(!hs.contains(s.charAt(right)))
			{
				hs.add(s.charAt(right++));
				maxLen =Math.max(maxLen,hs.size());
			}
			else 
			{
				hs.remove(s.charAt(left++));
			}
		}
		return maxLen;
    }
}
/*
*解题思路：
*1.建立HashSet，定义两个变量记录作为扫描记录。
*2.头变量每次扫描一个字符
*3.字符不存在于HashSet中，将字符加入HashSet，记录HashSet的最大长度
*4.字符存在于HashSet中，尾变量前移，直到无重复字符
*/