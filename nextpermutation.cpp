class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        const int len = nums.size();
        int j = len - 2;
        while (j >= 0) {
            int i = len - 1;
            while (i > j) {
                if (nums[i] > nums[j]) {
                    nums[i] ^= nums[j];
                    nums[j] ^= nums[i];
                    nums[i] ^= nums[j];
                    std::sort(nums.begin()+j+1, nums.end());
                    return;
                }
                i--;
            }
            j--;
        }
        if (j < 0) {
            std::reverse(nums.begin(), nums.end());
        }
    }
};
