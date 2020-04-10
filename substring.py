class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        longest = ""
        cur = ""
        cur_set = set()
        end = 0
        while (end < len(s)):
            if len(cur):    
                # TODO: fix cur_set
                if (s[end]) in cur:
                    cur_set = set()
                    idx = cur.find(s[end])
                    if idx < len(cur):
                        cur = cur[idx+1:]
                    else:
                        cur = ""
            cur_set.add(s[end])
            cur += s[end]
            if len(cur) > len(longest):
                longest = cur 
            end += 1
        return len(longest)
 

def main():
    print(Solution().lengthOfLongestSubstring("abcabcbb"))
    print(Solution().lengthOfLongestSubstring("pwwkew"))
    print(Solution().lengthOfLongestSubstring("bbbbb"))
    print(Solution().lengthOfLongestSubstring("dvdf"))


if __name__ == '__main__':
    main()
