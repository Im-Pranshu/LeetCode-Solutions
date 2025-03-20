class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;

        // Store occurrences in the map and check for duplicates immediately
        for (int num : nums) {
            mp[num]++;
            if (mp[num] > 1) {
                return true; // Duplicate found
            }
        }
        return 0;
    }
};