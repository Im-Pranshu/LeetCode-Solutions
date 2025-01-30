class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;

        // puri array ko check karo agar map hai to warna dal do map me
        for(int i=0; i<nums.size(); i++){
            // iska jo difference hai wo array me hoga to usko check karlo
            int complement = target - nums[i];
            
            // pure map me search karo agar hai to dono ke index ko return kardo
            if(mp.find(target - nums[i]) != mp.end())
                return {i, mp[target - nums[i]]};
            // warna index ko store kardo
            else
                mp[nums[i]] = i;
        }

        return {-1,-1};
    }
};