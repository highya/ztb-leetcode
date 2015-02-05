class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> v(s.length()+1,false);
        v[0]=true;
        for(int i=1;i<=s.length();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(v[j] && dict.find(s.substr(j,i-j))!=dict.end())
                {
                    v[i]=true;
                    break;
                }
            }
        }
        return v[s.length()];
    }
};
