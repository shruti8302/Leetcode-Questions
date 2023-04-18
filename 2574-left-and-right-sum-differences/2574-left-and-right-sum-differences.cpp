class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int left = 0;
        int right = 0;
        
        vector<int> res;
        
        if(nums.size() == 1){
            res.push_back(0);
            return res;
        }
        
        for(int i = 0; i < nums.size(); i++){
            right += nums[i];
        }
        
        
        
        for(int i = 0;i < nums.size()-1;i++){
            right = right - nums[i];
            int ans = abs(right - left);
            res.push_back(ans);
            left += nums[i];
        }
        res.push_back(left);
        return res;
    }
};