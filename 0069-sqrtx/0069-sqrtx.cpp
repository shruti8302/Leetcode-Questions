class Solution {
public:
    int mySqrt(int x) {
        
       int s = 0;
        int e = x;
        
        long long int mid = 0;
        
        long long int ans = 0;
        
        while(s <= e){
            
            mid = s + (e-s)/2;
            
            long long int square = mid*mid;
            
            if(square == x) return mid;
            
            if(square > x){
                e = mid-1;
            }else{
                ans = mid;
                s = mid + 1;
            }
        }
        
        return ans;
        
    }
};