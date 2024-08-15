class Solution {
public:
    int reverse(int x) {
        int num = abs(x);
        int answer = 0;
        while(num!=0){
            int digit = abs(num%10);
            if(answer > (INT_MAX - digit)/10)
            {
                return 0;
            }
            answer = answer*10 + digit;
            num = num/10;  
        }
        return (x < 0) ? (-answer) : answer;
    }
};