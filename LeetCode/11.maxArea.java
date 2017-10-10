public class Solution {
    public int maxArea(int[] height) {
        if(height.length<2)
		    return 0;
		
		int max =0;
		int left=0;
		int right = height.length-1;
		
		while (left<right)
		{
			int v = (right-left)*Math.min(height[left],height[right]);
			if(v>max)
				max =v;
			if(height[left]<height[right])
				left++;
			else 
				right--;
		}
		return max;
    }
}
/*解题思路：
 * 1.计算体积底乘高，因为装的液体，高应该是短的一端
 * 2.定义两个变量从两端扫描，小的移动一位，记录每次的体积
 */