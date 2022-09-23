class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1, flag = 0, x = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                prod *= nums[i];
            }
            else{
                flag++;
            }
        }
        vector <int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(flag == 0){
                ans.push_back(prod/nums[i]);
            }
            else if(nums[i] != 0 && flag == 1){
                ans.push_back(0);
            }
            else if(flag > 1){
                ans.push_back(0);
            }
            else{
                ans.push_back(prod);
            }
        }
        return ans;
    }
    
};