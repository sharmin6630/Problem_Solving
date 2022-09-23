class Solution {
    public boolean containsDuplicate(int[] nums) {
        Map<Integer, Integer> countNum = new HashMap<Integer, Integer>();
        for(int i = 0; i < nums.length; i++) {
            if(countNum.containsKey(nums[i])) {
                return true;
            }
            countNum.put(nums[i], 1);
        }
        return false;
    }
}