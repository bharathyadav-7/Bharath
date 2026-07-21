class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
       int low=0,high=n-1;
       while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target) return true;
        if(nums[low]==nums[mid] && nums[mid]==nums[high]){
            low+=1;
            high-=1;
            continue;
        }
        if(nums[low]<=nums[mid]){
            if(target>=nums[low] && target<=nums[mid]){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }else{
            if(target>=nums[mid]&&target<=nums[high]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
       }
       return false;
    
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna