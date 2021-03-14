class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> value_pos;
        for(int i=0;i<nums.size();i++)
        {
            int expect_value = target-nums[i];
            if(value_pos.count(expect_value)>0)
            {
                return {value_pos[expect_value],i};
            }
            value_pos[nums[i]] = i;
        }
        return {0,0};
    }
};