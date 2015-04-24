class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string,int> mp;
        vector<string> res;
        string s;
        for(int i=0;i<strs.size();i++)
        {
            s=strs[i];
            sort(s.begin(),s.end());
            if(mp.find(s)==mp.end())
            {
                mp[s]=i;
            }else{
                if(mp[s]>=0){
                    res.push_back(strs[mp[s]]);
                    mp[s]=-1;
                }
                res.push_back(strs[i]);
            }
        }
        return res;
    }
};
