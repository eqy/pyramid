class Solution {
public:
    bool search(vector<int>& nums, int target) {
        const int len = nums.size();
        int pivot;
        for (int i = 0; i < len; i++) {
            if (nums[i] == target) {
                return true;
            }
            if (i + 1 < len && nums[i] > nums[i+1]) {
                pivot = i;
                break;
            }
        }
        int start = 0;
        int end = len;
        while (end - start > 0) {
            int mid = (end + start)/2;
            const int curr = nums[(mid + pivot + 1) % len] ;
            if (curr == target) {
                return true;
            } else if (curr < target) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return false;
    }
};
