class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        // Store occurrences in the map and check for duplicates immediately
        for (int num : nums) {
            if (seen.find(num) != seen.end()) {
                return true; // Duplicate found
            }
            seen.insert(num);
        }
        return 0;
    }
};