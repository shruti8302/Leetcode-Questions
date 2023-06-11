class Solution {
public:
    
    void per(vector<int> &nums, vector<vector<int>> &ds, vector<int> &res, int *freq){
        if(res.size() == nums.size()){
            ds.push_back(res);
            return;
        }
        for(int i = 0;i < nums.size();i++){
            if(!freq[i]){
                res.push_back(nums[i]);
                freq[i] = 1;
                per(nums, ds, res, freq);
                res.pop_back();
                freq[i] = 0;
            }
        }
    }    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ds;
        vector<int> res;
        int n = nums.size();
        int *freq = new int[n];
        for(int i = 0;i < nums.size();i++) freq[i] = 0;
        per(nums, ds, res, freq);
        return ds;
    }
};