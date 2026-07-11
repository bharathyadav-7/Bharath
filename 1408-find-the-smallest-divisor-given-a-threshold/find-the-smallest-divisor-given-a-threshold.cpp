class Solution {
public:
double sumofD(vector<int> &nums,int div){
    int n=nums.size();
    double sum=0;
    for(int i=0;i<n;i++){
        sum+=ceil((double)nums[i]/(double)div);
    }
    return sum;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=0,high=*max_element( nums.begin(),nums.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(sumofD(nums,mid)<=threshold){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};