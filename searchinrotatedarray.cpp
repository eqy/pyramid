class Solution {
public:
    int findPivot(vector<int>& nums, int start, int end) {
        if (end - start < 16) {
            std::cout << nums[end] << std::endl;
            for (int i = start; i < end; i++) {
                if (nums[i] > nums[i+1]) {
                    return i + 1;
                }
            }
            return start;
        }
        int mid = ((end - start)/2) + start;
        if (nums[start] <= nums[mid] && nums[mid] <= nums[end]) {
            return start;
        } else if (nums[start] > nums[mid]) {
            return findPivot(nums, start, mid);
        } else {
            return findPivot(nums, mid, end);
        }
    }
    
    int _search(vector<int>& nums, int start, int end, int target) {
        if (nums[start] == target) {
            return start;
        }
        if (nums[end] == target) {
            return end;
        }
        if ((end - start) <= 3) {
            for (int i = start; i <= end; i++) {
                if (nums[i] == target) {
                    return i;
                }
            }
            return -1;
        }
        int mid = ((end - start)/2) + start;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            return _search(nums, start, mid, target);
        } else {
            return _search(nums, mid, end, target);
        }
    }
    
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if (size <= 3) {
            for (int i = 0; i < size; i++) {
                if (nums[i] == target) {
                    return i;
                }
            }
            return -1;
        }
        int pivot = findPivot(nums, 0, size - 1);
        if (pivot == 0) {
            return _search(nums, 0, size - 1, target);
        }
        if (nums[pivot] <= target && target <= nums[size - 1]){
            return _search(nums, pivot, size - 1, target);
        } else {
            return _search(nums, 0, pivot - 1, target);
        }
    }
};
