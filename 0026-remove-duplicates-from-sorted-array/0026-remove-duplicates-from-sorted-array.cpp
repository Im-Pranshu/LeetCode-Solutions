class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;

        for(int j=1; j<nums.size(); j++){
            if(nums[j] != nums[i]){
                i++;
                nums[i] = nums[j];
            }
        }

        // Return the no of unique elements in the vector.
        return i+1;
    }
};