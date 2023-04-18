class Solution {
public:
    int pivotInteger(int n) {
        
        long long sum = (n*(n+1))/2;
        
        long long s = 0;
        
        for(int i = 1; i <= n;i++){
            s += i;
            
            if(s == sum){
                return i;
            }
             sum -= i;
        }
        return -1;
    }
};