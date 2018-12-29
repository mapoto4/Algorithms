class Solution {
    public int strStr(String haystack, String needle) {
        int M = needle.length();
		int N = haystack.length();
		for(int i = 0;i<=N-M;i++)
		{
			int j;
			for(j=0;j<M;j++)
				if(haystack.charAt(i+j) != needle.charAt(j)){
					break;
				}
				if(j==M) 
					return i;
		}
		return -1;
    }
}
/*
	暴力字符查找算法
*/