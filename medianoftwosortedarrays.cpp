class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nums1_size = nums1.size();
        int nums2_size = nums2.size();
        if (!nums1_size && !nums2_size) {
            return 0;
        }
        
        if (!nums1_size) {
            if (nums2_size % 2) {
                return nums2[nums2_size/2];
            }
            return ((double) nums2[nums2_size/2 - 1] + (double)
nums2[nums2_size/2])/2;
        }
        if (!nums2_size) {
            if (nums1_size % 2) {
                return nums1[nums1_size/2];
            }
            return ((double) nums1[nums1_size/2 - 1] + (double)
nums1[nums1_size/2])/2;
        }
        
        int total_size = nums1_size + nums2_size;
        int merged_len = total_size / 2;
        int min_size1 = merged_len - nums2_size > 0 ? merged_len - nums2_size :
0;
        int max_size1 = nums1_size > merged_len ? merged_len : nums1_size;
        int size1 = (max_size1 - min_size1)/2 + min_size1;
        
        int med;
        
        while (true) {
            int size2 = merged_len - size1;
            if (!size2) {
                int last1 = nums1[size1 - 1];
                // no elements from nums2, so last1 must be smaller
                if (nums2[0] >= last1) {
                    int next = nums2[0];
                    if (size1 < nums1_size) {
                        next = nums1[size1] < next ? nums1[size1] : next;
                    }
                    if (total_size % 2) {
                        return next;
                    } else {
                        return ((double) last1 + (double) next)/2.0;
                    }
                } else {
                    max_size1 = size1 - 1;
                    size1 = (max_size1 - min_size1)/2 + min_size1;
                    continue;
                }
            }
            
            if (!size1) {
                int last2 = nums2[size2 - 1];
                // no elements from nums1, so last2 must be smaller
                if (nums1[0] >= last2) {
                    int next = nums1[0];
                    if (size2 < nums2_size) {
                        next = nums2[size2] < next ? nums2[size2] : next;
                    }
                    if (total_size % 2) {
                        return next;
                    } else {
                        return ((double) last2 + (double) next)/2.0;
                    }
                } else {
                    min_size1 = size1 + 1;
                    size1 = (max_size1 - min_size1)/2 + min_size1;
                    continue;
                }
            }
            int last1 = nums1[size1 - 1];
            int last2 = nums2[size2 - 1];
            if (size1 == nums1_size) {
                int past2 = nums2[size2];
                if (past2 >= last1) {
                    if (total_size % 2) {
                        return past2;
                    } else {
                        int prev = last2 > last1 ? last2 : last1;
                        return ((double) past2 + (double) prev)/2.0;
                    }
                } else {
                    max_size1 = size1 - 1;
                    size1 = (max_size1 - min_size1)/2 + min_size1;
                    continue;
                }
            }
            if (size2 == nums2_size) {
                int past1 = nums1[size1];
                if (past1 >= last2) {
                    if (total_size % 2) {
                        return past1;
                    } else {
                        int prev = last2 > last1 ? last2 : last1;
                        return ((double) past1 + (double) prev)/2.0;
                    }
                } else {
                    min_size1 = size1 + 1;
                    size1 = (max_size1 - min_size1)/2 + min_size1;
                    continue;
                }
            }
            int past1 = nums1[size1];
            int past2 = nums2[size2];
            if (past2 >= last1 && past1 >= last2) {
                if (past2 <= past1) {
                    if (total_size % 2) {
                        return past2;
                    } else {
                        int prev = last2 > last1 ? last2 : last1;
                        return ((double) past2 + (double) prev)/2.0;
                    }
                } else {
                    if (total_size % 2) {
                        return past1;
                    } else {
                        int prev = last2 > last1 ? last2 : last1;
                        return ((double) past1 + (double) prev)/2.0;
                    }
                }
            } else if (past2 < last1) {
                max_size1 = size1 - 1;
                size1 = (max_size1 - min_size1)/2 + min_size1;
            } else {
                min_size1 = size1 + 1;
                size1 = (max_size1 - min_size1)/2 + min_size1;
            }
        }
    }
};
