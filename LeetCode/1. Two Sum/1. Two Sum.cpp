class Solution {
public:
    vector <int> twoSum(vector <int> nums, int target) {
        map <int, int> mp;
        vector <int> ans;
        for(int i = 0; i < nums.size(); i++) {
            int check = target - nums[i];
            if (mp.count(check)) {
                ans.push_back(i);
                ans.push_back(mp[check]);
                break;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};