class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int sum = 0;
        
        int total = 0;
        
        for(int i = 0; i < nums.size(); i++){
            total += nums[i];
        }
        
        for(int i = 0;i < nums.size(); i++){
            if(2 * sum == total - nums[i]){
                return i;
            }
            sum += nums[i];
        }
        
        return -1;
        
    }
};