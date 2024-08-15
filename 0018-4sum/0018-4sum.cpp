class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        int n = nums.size();
        // 4 sum approach
        for(int h=0; h<=n-4; h++){
            
            // 3 sum approach
            for (int i = h+1; i <= n-3; i++){
            
            // 2 pointer approach is used inside this for loop.
            int j = i + 1;
            int k = n - 1; 
            while (j < k) {
                long sum = long(nums[i]) + long(nums[j]) + long(nums[k]) + long(nums[h]);
                if (sum == target) {
                    s.insert({nums[h], nums[i], nums[j],nums[k]});
                    j++;
                    k--;
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        }
        vector <vector<int>> output(s.begin() , s.end());
        return output;
    }
};