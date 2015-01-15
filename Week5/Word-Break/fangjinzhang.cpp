class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s.empty()) return false;
        if (dict.count(s) > 0) return true;
        
        int size = s.size();
        vector<vector<int> > table;
        for (int i = 0; i != size; ++i){
            table.push_back(vector<int> (size - i, 0));
            table[i][0] = dict.count(s.substr(i, 1));
        }
        for (int k = 2; k <= size; ++k){
            for (int i = 0; i <= size - k; ++i){
                table[i][k - 1] = dict.count(s.substr(i, k));
                if (table[i][k - 1]) continue;
                for (int j = 1; j <= k - 1; ++j){
                    if (table[i][j - 1] && table[i + j][k - j - 1]){
                        table[i][k - 1] = 1;
                        break;
                    }
                }
            }
        }
        return table[0][size - 1];
    }
};
