class Solution {
public:
    int uniquePaths(int m, int n) {
        
        if(m == 1 || n == 1){
            return 1;
        }
        
        int N = m + n - 2;
        
        int f = min(m,n)-1;
        long long int ans = 1;
        
        for(long long int i = 1;i <= f;i++,N--){
            ans = (ans*N)/i;
        }
        
    
        return ans;
            
    }
};