class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int> hash(256, -1);
        int l = 0, r = 0, maxLen = 0, len = 0;

        while (r < n) {
            if (hash[s[r]] != -1) {
                if (hash[s[r]] >= l) {
                    l = hash[s[r]] + 1;
                }
            }
            len = r - l + 1;
            maxLen = max(len, maxLen);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
}; 