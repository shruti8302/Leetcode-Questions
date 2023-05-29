class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int si = 0;
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        int ei = n-1;
        
        while(si <= ei){
            int mid = si + (ei-si)/2; //to avoid integer overflow
            
            if(mid > 0 && mid < ei){
                if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                    return mid;
                }else if(nums[mid] > nums[mid-1]){
                    si = mid+1;
                }else{
                    ei = mid-1;
                }
            }else if(mid == 0){
                if(nums[mid] > nums[mid+1]){
                    return mid;
                }else{
                    return mid+1;
                }
            }else if(mid == ei){
                if(nums[mid] > nums[mid-1]){
                    return mid;
                }else{
                    return mid-1;
                }
            }
        }
        return 0;
    }
};