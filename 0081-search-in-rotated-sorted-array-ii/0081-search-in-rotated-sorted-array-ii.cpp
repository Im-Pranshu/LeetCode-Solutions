class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();  // Get the size of the input vector
        
        // Initialize variables for Binary Search
        int s = 0, e = n - 1 , m; // 's' is the start index, 'e' is the end index, 'm' will be the middle index

        // Perform Binary Search
        while(s <= e) {
            m = s + (e - s) / 2; // Calculate the mid-point to avoid potential overflow

            // Check if the element at the mid of the current range is the target
            if(nums[m] == target) 
                return true; // Target found, return true

            // Check if the left portion is sorted
            if(nums[s] < nums[m]) {
                // Check if the target lies within the sorted left portion
                if(nums[s] <= target && target < nums[m])
                    e = m - 1;  // Narrow the search to the left portion by adjusting the end index
                else
                    s = m + 1;  // Narrow the search to the right portion by adjusting the start index
            }
            // If the left portion is not sorted, the right portion must be sorted
            else if(nums[s] > nums[m]) {
                // Check if the target lies within the sorted right portion
                if(nums[m] < target && target <= nums[e])
                    s = m + 1;  // Narrow the search to the right portion by adjusting the start index
                else
                    e = m - 1;  // Narrow the search to the left portion by adjusting the end index
            }
            // If nums[s] == nums[m], we cannot determine which side is sorted, move 's' forward to skip the duplicate
            else
                s += 1;
        }

        // If the element is not found in the vector after searching
        return false;
    }
};