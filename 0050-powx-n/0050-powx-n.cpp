class Solution {
public:
    double myPow(double x, int n) {
        if (n == INT_MAX) return (x == 1) ? 1 : (x == -1) ? -1 : 0;
        if (n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;
        if(n < 0){
            n = abs(n);
            x = 1/x;
        }
        double ans = 1;
        
        while(n > 0){
            if(n % 2 == 1){
                ans *= x;
                n=n-1;
            }else{
                x = x*x;
                n= n/2;
            }
        }
        
        return ans;
    }
};