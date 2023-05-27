class Solution {
public:
    
    int pivot(vector<int>& arr){
        int si = 0;
        int ei = arr.size()-1;
        int n = arr.size();
        if(arr[si] <= arr[ei]){
            return 0;
        }
        while(si <= ei){
            int mid = si + (ei-si)/2;
            int prev = (mid-1+n)%n;
            int next = (mid+1)%n;
            
            if(arr[mid] <= arr[next] && arr[mid] <= arr[prev]){
                return mid;
            }else if(arr[mid] >= arr[0]){
                si = mid+1;
            }else if(arr[mid] <= arr[ei]){
                ei = mid-1;
            }
        }
        return -1;
    }
    
    int bs(vector<int>& nums,int si, int ei, int target){
        
        while(si <= ei){
            int mid = si + (ei-si)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                si = mid+1;
            }else{
                ei = mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        if(n == 1){
            if(nums[0] == target) return 0;
            else return -1;
        }
        
        int p = pivot(nums);
        
        
        if(nums[p] == target){
            return p;
        }
        int a1 = bs(nums,p,n-1,target);
        int a2 = bs(nums,0,p-1,target);
        
        if(a1 != -1) return a1;
        else return a2;
    
        return -1;
    }
};