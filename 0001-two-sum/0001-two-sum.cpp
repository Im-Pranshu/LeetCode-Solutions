class Solution {
public:
    // Function to find two indices such that their values add up to the target
vector<int> twoSum(vector<int>& nums, int target) {
    // Create a hash map to store value-to-index mappings
    unordered_map<int, int> mp;

    // Iterate through the array
    for (int i = 0; i < nums.size(); i++) {
        
        // Calculate the complement that would sum with nums[i] to reach the target
        int complement = target - nums[i];

        // Check if the complement is already in the map (i.e., it was seen in a previous iteration)
        if (mp.find(complement) != mp.end()) {
            // If found, return the indices of the current value and the value that was previously stored
            return {i, mp[complement]};
        } else {
            // Otherwise, store the current value and its index in the map
            // This will help in finding its complement in future iterations
            mp[nums[i]] = i;
        }
    }

    // If no pair is found that adds up to the target, return {-1, -1}
    return {-1, -1};
}
};