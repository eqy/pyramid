class Solution2 {
public:
    bool isMatch(int pos, const string s, const vector<string>& words,
std::set<std::string> word_set, std::unordered_map<std::string, int> word_map) {
        const int len = s.size();
        const int wordlen = words[0].size();
        while (pos + wordlen*word_set.size() <= len) {
            // current substring
            const std::string cur_substr = s.substr(pos, wordlen);
            // word matches in set 
            if (word_set.find(cur_substr) != word_set.end()) {
                word_map[cur_substr]--;
                if (!word_map[cur_substr]) {
                    word_set.erase(cur_substr);
                }
                // if done
                if (!word_set.size()) {
                    return true;
                } 
                pos += wordlen;
            // does not match in set
            } else {
                return false;
            }
        }
        return false;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        const int len = s.size();
        const int n_words = words.size();
        std::vector<int> res;
        if (!n_words) {
            return res;
        } 
        std::set<std::string> word_set;
        std::unordered_map<std::string, int> word_map;
        for (auto it = words.begin(); it != words.end(); it++) {
            word_set.insert(*it);
            if (word_map.find(*it) == word_map.end()) {
                word_map[*it] = 1;
            } else {
                word_map[*it]++;
            }
        } 
        const int wordlen = words[0].size();
        for (int i = 0; i + wordlen*n_words <= len; i++) {
            if (isMatch(i, s, words, word_set, word_map)) {
                res.push_back(i);
            }
        }
        return res;
    }
};


class Solution {
public:
    bool isMatch(int pos, const string s, const vector<string>& words,
std::unordered_map<std::string, int> word_map) {
        const int len = s.size();
        const int wordlen = words[0].size();
        int remaining = words.size();
        while (pos + wordlen*remaining <= len) {
            // current substring
            const std::string cur_substr = s.substr(pos, wordlen);
            // word matches in set 
            if (word_map.find(cur_substr) != word_map.end()) {
                word_map[cur_substr]--;
                remaining--;
                if (word_map[cur_substr] < 0) {
                    return false;
                }
                // if done
                if (!remaining) {
                    return true;
                } 
                pos += wordlen;
            // does not match in set
            } else {
                return false;
            }
        }
        return false;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        const int len = s.size();
        const int n_words = words.size();
        std::vector<int> res;
        if (!n_words) {
            return res;
        } 
        //std::set<std::string> word_set(words.begin(), words.end());
        std::unordered_map<std::string, int> word_map;
        for (auto it = words.begin(); it != words.end(); it++) {
            //word_set.insert(*it);
            if (word_map.find(*it) == word_map.end()) {
                word_map[*it] = 1;
            } else {
                word_map[*it]++;
            }
        } 
        const int wordlen = words[0].size();
        for (int i = 0; i + wordlen*n_words <= len; i++) {
            if (isMatch(i, s, words, word_map)) {
                res.push_back(i);
            }
        }
        return res;
    }
};
