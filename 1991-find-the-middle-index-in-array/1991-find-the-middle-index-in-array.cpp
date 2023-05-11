class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        long long int rightSum = 0;
        
        for(int i = 0;i < nums.size();i++){
            rightSum += nums[i];
        }
        
        int leftSum = 0;
        
        for(int i = 0;i < nums.size();i++){
            rightSum -= nums[i];
            if(leftSum == rightSum){
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};