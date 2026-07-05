class Solution {
public:
    int merge(vector<int>& nums, int left, int mid, int right) {
        int cnt = 0;
        int rightCnt = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (rightCnt <= right &&
                   (long long)nums[i] > 2LL * nums[rightCnt]) {
                rightCnt++;
            }
            cnt += (rightCnt - (mid + 1));
        }
        vector<int> temp;
        int low = left;
        int high = mid + 1;
        while (low <= mid && high <= right) {
            if (nums[low] <= nums[high]) {
                temp.push_back(nums[low]);
                low++;
            }
            else {
                temp.push_back(nums[high]);
                high++;
            }
        }
        while (low <= mid) {
            temp.push_back(nums[low]);
            low++;
        }
        while (high <= right) {
            temp.push_back(nums[high]);
            high++;
        }
        for (int i = 0; i < temp.size(); i++) {
            nums[i + left] = temp[i];
        }
        return cnt;
    }
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return 0;
        }
        int cnt = 0;
        int mid = left + (right - left) / 2;
        cnt += mergeSort(nums, left, mid);
        cnt += mergeSort(nums, mid + 1, right);
        cnt += merge(nums, left, mid, right);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};