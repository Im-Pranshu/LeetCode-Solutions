int firstOccurrence(vector<int> arr,int n,int key){
    int s=0,e=n-1;
    int mid = s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(arr[mid] == key){
            ans = mid;
            e=mid-1;
        }
        else if(arr[mid]>key)
            e = mid-1;
        else 
            s = mid+1;
        mid = s+(e-s)/2;
    }
    return ans;
}
int lastOccurrence(vector<int> arr,int n,int key){
    int s=0,e=n-1;
    int mid = s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(arr[mid] == key){
            ans = mid;
            s=mid+1;
        }
        else if(arr[mid]>key)
            e = mid-1;
        else 
            s = mid+1;
        mid = s+(e-s)/2;
    }
    return ans;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n= nums.size();
        int a = firstOccurrence(nums,n,target);
        int b = lastOccurrence(nums,n,target);
        return {a,b};
    }

};