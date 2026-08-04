class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        mpp[0]=1;
        int presum=0,count=0;
        for(int i=0;i<nums.size();i++){
            presum += nums[i];
            int remove=presum-k;
            count += mpp[remove];
            mpp[presum] +=1;
        }
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna