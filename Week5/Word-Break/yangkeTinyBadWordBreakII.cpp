class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        if(dict.size()==0){
            return vector<string>();
        }
        int n=s.length();
        vector<vector<string> *> dp(n+1,NULL);
        vector<string> canary;
        canary.push_back(string("^"));
        dp[0]=&canary;
        for(int i=1;i<=n;i++)
        {
            if(dp[i-1]!=NULL)
            {
                int idx=i-1;
                for(int j=idx;j<n;j++)
                {
                    string cur=s.substr(idx,j-idx+1);
                    if(dict.count(cur)>0)
                    {
                        vector<string> *tmp= new vector<string>();
                        for(int k=0;k<(int)dp[i-1]->size();k++)
                        {
                            tmp->push_back((*dp[i-1])[k]+" "+cur);
                        }
                        if(dp[j+1]==NULL){
                            dp[j+1]=tmp;
                        }else{
                            for(int k=0;k<(int)tmp->size();k++)
                            {
                                dp[j+1]->push_back((*tmp)[k]);
                            }
                        }
                    }
                }
            }
        }
        if(dp[n]){
          for(int i=0;i<(int)dp[n]->size();i++)
          {
            (*dp[n])[i]=(*dp[n])[i].substr(2,(*dp[n])[i].length()-2);
          }
          return *dp[n];
        }else{return vector<string>();}
    }
};
