class Solution {
public:
    string minWindow(string s, string t) {
        int minstart = -1;
        int minend;
        int mindist = -1;
        int curminpos = -1;
        std::map<char, int> reqcounts;
        std::map<char, int> foundcounts;
        int foundcount = 0;
        int reqcount = 0;
        const int tlen = t.size();
        const int slen = s.size();
        if (tlen > slen) {
            return "";
        }

        for (int i = 0; i < tlen; i++) {
            const char curr = t[i];
            reqcounts[curr]++;
            foundcounts.insert(std::pair<char, int>({curr, 0}));
            reqcount++;
        }
        for (int i = 0; i < slen; i++) {
            const char curr = s[i];
            auto res = foundcounts.find(curr);

            if (res != foundcounts.end()) {
                const int currcount = res->second;
                if (currcount < reqcounts[curr]) {
                    foundcount++;
                    foundcounts[curr] = currcount + 1;
                    if (curminpos < 0) {
                        curminpos = i;
                    }
                    while (foundcount == reqcount) {
                        const int dist = i - curminpos;
                        if (mindist < 0 || dist < mindist) {
                            mindist = dist;
                            minstart = curminpos;
                            minend = i - curminpos + 1;
                        }
                        char windowstart = s[curminpos];
                        const int windowstartcount = foundcounts[windowstart] -
1;
                        foundcounts[windowstart] = windowstartcount;
                        if (windowstartcount < reqcounts[windowstart]) {
                            foundcount--;
                        }
                        curminpos++;
                        while (curminpos < i) {
                            windowstart = s[curminpos];
                            auto windowstartres = foundcounts.find(windowstart);
                            if (windowstartres == foundcounts.end()) {
                                curminpos++;
                            } else {
                                const int windowstartcount =
windowstartres->second;
                                if (windowstartcount <= reqcounts[windowstart])
{
                                    break;
                                } else {
                                    foundcounts[windowstart] = windowstartcount
- 1;
                                    curminpos++;
                                }
                            }
                        }
                    } 
                } else {
                    foundcounts[curr] = currcount + 1;
                }
            }
        }
        if (minstart < 0) {
            return "";
        }
        return s.substr(minstart, minend);
    }
};
