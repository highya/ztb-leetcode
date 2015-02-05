class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        vector<bool> v(n + 1, false);
        v[0] = true;
        for (int i = 0; i < n; i++) {
            if (v[i]) {
                for (int len = 1; len < n + 1 - i; len++) {
                    if (dict.count(s.substr(i, len)) > 0)
                        v[i + len] = true;
                }
            }
        }
        return v[n];
    }
};
