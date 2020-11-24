class Solution {
public:
    // cur aaaaaaaaaaaaab a*a*a*a*a*a*a*a*a*a*c
    // cur b a*a*a*a*a*a*a*a*a*c
    bool _isMatch(const string& s, const string& p, int s_pos, int p_pos, int
*map) {
        int s_len = s.length();
        int p_len = p.length();
        int cur_s_len = s_len - s_pos;
        int cur_p_len = p_len - p_pos;
        if (!cur_s_len && !cur_p_len) {
            return true;
        } else if (cur_p_len) {
            if (map[s_pos*(p_len + 1) + p_pos] >= 0) {
                return map[s_pos*(p_len + 1) + p_pos];
            }
            if (!cur_s_len) {
                if (p[p_pos] == '*') {
                    bool res = _isMatch(s, p, s_pos, p_pos+1, map);
                    map[s_pos*(p_len + 1) + p_pos] = res;
                    return res;
                } else if (cur_p_len > 1 && p[p_pos+1] == '*') {
                    bool res = _isMatch(s, p, s_pos, p_pos+2, map);
                    map[s_pos*(p_len + 1) + p_pos] = res;
                    return res;
                } else {
                    return false;
                }
            }
            if (p[p_pos] == '.') {
                if (cur_p_len > 1 && p[p_pos + 1] == '*') {
                    bool res = _isMatch(s, p, s_pos + 1, p_pos + 1, map) ||
_isMatch(s, p, s_pos, p_pos + 1, map);
                    map[s_pos*(p_len + 1) + p_pos] = res;
                    return res;
                } else {
                    bool res = _isMatch(s, p, s_pos + 1, p_pos + 1, map);
                    map[s_pos*(p_len + 1) + p_pos] = res;
                    return res;
                }
            } else if (p[p_pos] == '*') {
                if (p[p_pos-1] == s[s_pos] || p[p_pos-1] == '.' ) {
                    bool res = _isMatch(s, p, s_pos + 1, p_pos, map) ||
_isMatch(s, p, s_pos + 1, p_pos + 1, map) || _isMatch(s, p, s_pos, p_pos+1,
map);
                    map[s_pos*(p_len + 1) + p_pos] = res;
                    return res;
                } else {
                    bool res = _isMatch(s, p, s_pos, p_pos + 1, map);
                    map[s_pos*(p_len + 1) + p_pos] = res;
                    return res;
                }
            } else {
                if (cur_p_len > 1) {
                    if (p[p_pos + 1] == '*') {
                        bool res =  _isMatch(s, p, s_pos, p_pos + 1, map);
                        map[s_pos*(p_len + 1) + p_pos] = res;
                        return res;
                    } else {
                        if (p[p_pos] == s[s_pos]) {
                            bool res = _isMatch(s, p, s_pos + 1, p_pos + 1,
map);
                            map[s_pos*(p_len + 1) + p_pos] = res;
                            return res;
                        } else {
                            return false;
                        }
                    }
                } else {
                    if (p[p_pos] == s[s_pos]) {
                        bool res =  _isMatch(s, p, s_pos + 1, p_pos + 1, map);
                        map[s_pos*(p_len + 1) + p_pos] = res;
                        return res;
                    } else {
                        return false;
                    }
                }
            }
        } else {
            return false;
        }
    }
    
    bool isMatch(string s, string p) {
        int * map = new int[(s.length()+1)*(p.length()+1)];
        std::fill(map, map+(s.length()+1)*(p.length()+1), -1);
        bool res =  _isMatch(s, p, 0, 0, map);
        delete [] map;
        return res;
    }
};
