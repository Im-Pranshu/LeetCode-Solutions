class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;

        bool sign = true;

        if(dividend >= 0 && divisor < 0) sign = false;
        else if(dividend <= 0 && divisor > 0) sign = false;

        long n = abs(dividend) , d = abs(divisor), ans = 0;

        while(n >= d){
            int cnt = 0;
            while(n >= (d << (cnt+1) )){
                cnt += 1;
            }

            ans += 1 << cnt;
            
            n -= (d << cnt);
        }

        if (ans ==  (1<<31) && sign == true)  return INT_MAX;
        else if (ans == (1<<31) && sign == false) return INT_MIN;
        cout << ans;
        return sign ? ans : -1 * ans;
    }
};