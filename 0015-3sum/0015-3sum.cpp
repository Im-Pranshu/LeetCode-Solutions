class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        for (int i = 0; i < nums.size()-2; i++){
            // 2 pointer approach is used inside this for loop.
            int j = i + 1;
            int k = nums.size() - 1;
            // cout << i << k << endl; 
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                // cout << sum << endl;;
                if (sum == target) {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        vector <vector<int>> output(s.begin() , s.end());
        return output;
    }
};