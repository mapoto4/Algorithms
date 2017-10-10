public class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        int []result=new int[]{0,1};
        
        for(int i=0;i<nums.length;i++)
        {
            if(map.containsKey(target-nums[i]))
            {
                result[1] = i;
                result[0] = map.get(target-nums[i]);
                return result;
            }
            else 
            {
                map.put(nums[i],i);            
            }
        }
        return result;
    }
}