class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;

        // store the occurence in the map 
        for(auto it: nums){
            mp[it]++;
        }

        // // if occurence is more than once then duplicate exist
        // for(int i=0; i<mp.size(); i++){
        //     if(mp[i] > 1){
        //         return 1;
        //     }
        // }
        for (auto& it : mp) {
            if (it.second > 1) {
                return true; // Duplicate exists
            }
        }
        return 0;
    }
};