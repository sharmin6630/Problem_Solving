class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] answer = new int [nums.length];
        int flag = 0, multiply = 1;
        for(int i = 0; i < nums.length; i++){
            if(nums[i] == 0) { 
                flag = flag + 1;
                continue;
            }
            multiply = multiply * nums[i];
        }
        for(int i = 0; i < nums.length; i++) {
            if(flag > 1) {
                answer[i] = 0;
            } 
            else if(flag == 1 && nums[i] != 0) {
                answer[i] = 0;
            }
            else if(flag == 1 && nums[i] == 0) {
                answer[i] = multiply;
            }
            else
                answer[i] = multiply / nums[i];
        }
        return answer;
    }
}