#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> overlap(const vector<int> &a, const vector<int> &b) {
        // b starts after a
        if (a[1] >= b[0] && a[0] <= b[0]) {
            std::vector<int> res = {a[0], b[1] > a[1] ? b[1] : a[1]};
            return res;
        } 
        // a starts after b
        if (b[1] >= a[0] && b[0] <= a[0]) {
            std::vector<int> res = {b[0], a[1] > b[1] ? a[1] : b[1]};
            return res;
        }
        std::vector<int> res;
        return res;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        struct {
            bool operator() (const std::vector<int>& a, const std::vector<int> & b) {
                return a[0] < b[0];
            }
        } comp;
        std::sort(intervals.begin(), intervals.end(), comp);
        int size = intervals.size();
        std::vector<std::vector<int>> merged_intervals;
        if (size <= 1) {
            // lol
            return intervals;
        }
        merged_intervals.push_back(intervals[0]);
        int done = 1;
        int i = 1;
        while (i < size) {
            auto res = overlap(merged_intervals[done - 1], intervals[i]);
            if (res.size()) {
                merged_intervals[done - 1] = res;
            } else {
                done++;
                merged_intervals.push_back(intervals[i]);
            }
            i++;
        }
        return merged_intervals;
    }
};

int main(void) {
    //std::vector<std::vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    std::vector<std::vector<int>> intervals = {{2,3},{4,5},{6,7},{8,9},{1,10}};
    std::vector<std::vector<int>> intervals2 = {{1,4},{4,5}};
    auto res = Solution().merge(intervals);
    auto res2 = Solution().merge(intervals2);
    for (auto it = res.begin(); it != res.end(); it++) {
        for (auto it2 = it->begin(); it2 != it->end(); it2++) {
            std::cout << *it2 << " ";    
        }
        std::cout << std::endl;
    }
    for (auto it = res2.begin(); it != res2.end(); it++) {
        for (auto it2 = it->begin(); it2 != it->end(); it2++) {
            std::cout << *it2 << " ";    
        }
        std::cout << std::endl;
    }
    return 0;
}
