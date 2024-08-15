int getPivot(vector<int> v, int n){
    int s=0 , e=n-1;
    int mid = s+(e-s)/2;
    while(s<e){
        if(v[mid] >= v[0]){
            s = mid+1;
        }
        else
            e = mid;
        mid = s+(e-s)/2;
    }
    return mid;
}

int binarySearch(vector<int> v,int n,int s,int e , int target){
    int mid = s+(e-s)/2;
    while(s<=e){
        if(v[mid] == target){
            return mid;
        }
        else if(v[mid] < target)
            s = mid+1;
        else 
            e = mid-1;
        mid = s + (e-s)/2;
    }
    return -1;
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
    int n = nums.size();
    int pivot = getPivot(nums, n);
    if(nums[pivot] <= target && target <= nums[n-1])
        return binarySearch(nums, n, pivot , n-1, target);
    else
        return binarySearch(nums, n, 0 , pivot-1, target);
    }
};