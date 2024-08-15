class Solution {
public:
    long long int binarySearch(int num){
        int s=0;
        int e=num;
        long long int mid = s+(e-s)/2;
        long long int ans=0;
        while(s<=e){
            long long int square = mid*mid;
            if(square > num)
                e = mid-1;
            else if(square <= num){
                ans = mid;
                s = mid+1;
            }
            mid = s+(e-s)/2;
        }
        return ans;
    }
    int mySqrt(int x) {
        return binarySearch(x);
    }
};