class Solution {
public:
    bool isPalindrome(int x) {
        long long ans=0 , temp=x;
        if (x < 0) return false;
        while(temp!=0){
            int dig = temp%10;
            ans = ans*10+dig;
            temp /= 10;
        }
        if(ans == x)
            return true;
        else
            return false;
    }
};