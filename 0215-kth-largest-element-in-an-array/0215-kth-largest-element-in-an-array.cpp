class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // make min heap.
        priority_queue <int, vector<int>, greater<int> > pq;
        
        // insert first k-1 elements
        for(int i=0; i<k; i++) 
            pq.push(nums[i]);

        // loop from k to n-1
        for(int i=k; i<nums.size(); i++){
            // nums[i] > root
            if(nums[i] > pq.top()){
                pq.pop();// remove root
                pq.push(nums[i]); // insert element
            }

        }

        // return kth largest element.
        return pq.top();
    }
};