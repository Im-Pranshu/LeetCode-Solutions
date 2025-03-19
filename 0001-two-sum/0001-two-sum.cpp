class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;

        for(int i=0; i<nums.size(); i++){
            int complement = target - nums[i];

            if(mp.find(complement) != mp.end()){
                return {i, mp[complement]};
            }
            
            // map me index store karlo kuki index hi return karna hai
            mp[nums[i]] = i;
            
        }

        return {-1,-1};
    }
};