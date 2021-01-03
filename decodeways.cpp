class Solution {
public:
    int _numDecodings(const string& s) {
        const int length = s.size();
        if (!length) {
            return 0;
        } else if (length == 1) {
            return s[0] != '0';
        } else if (length == 2) {
            int res = 0;
            if (s[1] != '0') {
                res = 1;
            }
            if (s[0] == '0') {
                return 0;
            }
            if ((s[0] == '1'  || (s[0] == '2' && s[1] <= '6'))) {
                res++;
            }
            return res;
        }
        int dp[length+1];
        dp[length] = 0;
        dp[length-1] = 0;
        if (s[length-1] != '0') {
            dp[length-1] = 1;
        }
        if (s[length-2] != '0') {
            dp[length-2] = dp[length-1];
        } else {
            dp[length-2] = 0;
        }
        if ((s[length-2] == '1'  || (s[length-2] == '2' && s[length-1] <= '6')))
{
            dp[length-2]++;
        }
        for (int i = length-3; i >= 0; i--) {
            int decodings = 0;
            if (s[i] != '0') {
                decodings += dp[i+1];
                if ((s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))) {
                    decodings += dp[i+2];
                } 
            }
            dp[i] = decodings;
        }
        return dp[0];
    }
    
    int numDecodings(string s) {
        return _numDecodings(s);
    }
};
