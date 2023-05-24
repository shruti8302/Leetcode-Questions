class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i = 0;i < n;i++){
            for(int j = 1;j < m;j++){
                mat[i][j]+=mat[i][j-1];
            }
        }
        unordered_map<int, int> mp;
        int res = 0;
        
        for(int c1 = 0;c1 < m;c1++){
            for(int c2 = c1;c2 < m;c2++){
                mp.clear();
                mp[0] = 1;
                int sum = 0;
                for(int r = 0;r < n;r++){
                    if(c1 > 0){
                        sum += mat[r][c2]-mat[r][c1-1];
                    }else{
                        sum += mat[r][c2];
                    }
                    if(mp.find(sum-target) != mp.end()){
                        res += mp[sum-target];
                    }
                    mp[sum]++;
                }
            }
        }
        return res;
    }
};