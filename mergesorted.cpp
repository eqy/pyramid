#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    void insert(vector<int>& nums1, int pos, int m, int val) {
        for (int i = m - 1; i > pos; i--) {
            nums1[i] = nums1[i-1];
        }
        nums1[pos] = val;
    }
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos1 = 0;
        int pos2 = 0;
        const int total_len = m + n;
        while (pos1 < total_len && pos2 < n) {
            const int cur1 = nums1[pos1];
            const int cur2 = nums2[pos2];
            if (cur1 > cur2 || pos1 >= (m + pos2)) {
                // nums1.insert(nums1.begin() + pos1, cur2);
                insert(nums1, pos1, m + n, cur2);
                pos1++;
                pos2++;
            } else {
                pos1++;
            }
        }
    }
};


int main(void) {
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2 = {2, 5, 6};
    int m = 3;
    int n = 3;
    Solution().merge(nums1, m , nums2, n);
    for (auto it = nums1.begin(); it != nums1.end(); it++) {
        std::cout << *it << std::endl;
    }
}
