class Solution {
public:
    int climbedStairs(int cur, int n) {
        if (cur > n) {
            return 0;
        } else if (cur == n) {
            return 1;
        } else {
            auto first = memo.find(cur + 1);
            auto second = memo.find(cur + 2);
            int cur1;
            int cur2;
            if (first != memo.end()) {
                cur1 = first->second;
            } else {
                cur1 = climbedStairs(cur + 1, n);
                memo.insert({cur + 1, cur1});
            }
            if (second != memo.end()) {
                cur2 = second->second;
            } else {
                cur2 = climbedStairs(cur + 2, n);
                memo.insert({cur + 2, cur2});
            }
            return cur1 + cur2;
        }
    }
    int climbStairs(int n) {
        return climbedStairs(0, n);
    }
    std::unordered_map<int, int> memo;
};
