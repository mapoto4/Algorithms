public class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] nums3 = new int[nums1.length+nums2.length];
		System.arraycopy(nums1, 0, nums3, 0, nums1.length);  
		System.arraycopy(nums2, 0, nums3, nums1.length, nums2.length);  
		Arrays.sort(nums3);
		
		int left = 0;
		int right = nums3.length-1;
		int len = nums3.length;
		while(len>2)
		{
			left++;
			right--;
			len=len-2;
		}
		double result = nums3[left]+nums3[right];
		result = result / 2;
		return result;	
    }
}

/*解题思路：
*1.将a,b两个数组合并成一个数组c，使之有序。
*2.定义两个变量，从数组c两端开始同步扫描，记录两个变量之间的距离。
*3.当两个变量不大于2时，返回此时扫描坐标
*4.计算两个坐标在数组c中的平均值
*/