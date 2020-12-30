class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        std::vector<std::vector<string>> lines;
        std::vector<int> linewidths;
        int wordcount = words.size();
        int currentwidth = 0;
        int currentwordwidth = 0;
        std::vector<string> currentwords;
        std::vector<string> result;
        for (int i = 0; i < wordcount; i++) {
            const std::string cur_word = words[i];
            const int wordwidth = cur_word.size();
            if (currentwidth && (wordwidth + currentwidth + 1 > maxWidth)) {
                linewidths.push_back(currentwordwidth);
                lines.push_back(currentwords);
                currentwords = std::vector<string>({cur_word});
                currentwidth = cur_word.size();
                currentwordwidth = cur_word.size();
            } else {
                currentwords.push_back(cur_word);
                if (currentwidth) {
                    currentwidth += 1;
                }
                currentwidth += wordwidth;
                currentwordwidth += wordwidth;
            }
        }
        if (currentwords.size()) {
            lines.push_back(currentwords);
            linewidths.push_back(currentwidth);
        }
        const int linecount = lines.size();
        for (int i = 0; i < linecount - 1; i++) {
            const int currentwordcount = lines[i].size();
            const int spacecount =  currentwordcount > 1 ? currentwordcount - 1
: 1;
            const int currentwidth = linewidths[i];
            const int diff = maxWidth - currentwidth;
            const int spacewidth = diff/spacecount;
            int spaceresid = diff % spacecount;
            std::string curoutline;
            curoutline.reserve(maxWidth);
            int pos = 0;
            for (int j = 0; j < currentwordcount; j++) {
                const std::string word = lines[i][j];
                curoutline.insert(pos, word);
                pos += word.size();
                if (j + 1 < currentwordcount || currentwordcount == 1) {
                    for (int k = 0; k < spacewidth; k++) {
                        curoutline.insert(pos, " ");
                        pos++;
                    }
                    if (spaceresid) {
                        curoutline.insert(pos, " ");
                        pos++;
                        spaceresid--;
                    }
                }
            }
            result.push_back(curoutline);
        }
        std::string curoutline;
        curoutline.reserve(maxWidth);
        int pos = 0;
        const int currentwordcount = lines[linecount-1].size();
        for (int j = 0; j < currentwordcount; j++) {
            const std::string word = lines[linecount-1][j];
            curoutline.insert(pos, word);
            pos += word.size();
            if (j + 1 < currentwordcount) {
                curoutline.insert(pos, " ");
                pos++;
            }
        }
        for (int k = pos; k < maxWidth; k++) {
            curoutline.insert(pos, " ");
        }
        result.push_back(curoutline);
        return result;
    }
};
