class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        if(dict.size()==0){
            return vector<string>();
        }
        int max=0;
        int min=INT_MAX;
        for(unordered_set<string>::iterator it = dict.begin();it!=dict.end();it++)
        {
            string word=*it;
            if(word.length()<min)min=word.length();
            if(word.length()>max)max=word.length();
        }
        return wordBreakHelper(s,dict,max,min);
    }
    vector<string> wordBreakHelper(string s, unordered_set<string> &dict,int max,int min){
        
        int n=s.length();
        vector<vector<int>*> dp(n+1,NULL);
        vector<int> canary;
        //canary.push_back());
        dp[0]=&canary;
        for(int i=1;i<=n;i++)
        {
            if(dp[i-1]!=NULL)
            {
                int idx=i-1;
                for(int j=idx+min-1;j<(idx+max<n?idx+max:n);j++)
                //note the init of j,idx itself is a char in the cur,so j shoud start from it.
                //imagine the case when min=1 so j should start from idx=idx+1-1=idx+min-1.
                {
                    string cur=s.substr(idx,j-idx+1);
                    if(dict.count(cur)>0)
                    {
                        if(dp[j+1]==NULL){
                            vector<int> *tmp= new vector<int>();
                            tmp->push_back(idx);
                            dp[j+1]=tmp;
                        }else{
                            dp[j+1]->push_back(idx);
                        }
                    }
                }
            }
        }
        if(dp[n]){
            return retain(s,dp,n);
        }else{
            return vector<string>();
        }
    }
    vector<string> retain(string s,vector<vector<int>*> dp,int n)
    {
        vector<string> result;
        if(n==0){
            result.push_back("");
            return result;
        }
        for(int i=0;i<dp[n]->size();i++)
        {
            int idx=(*dp[n])[i];
            string right=s.substr(idx,n-idx);
            vector<string> lefts=retain(s,dp,idx);
            for(int i=0;i<lefts.size();i++)
            {
                string one;
                if(lefts[i]=="")one=right;
                else one=lefts[i]+" "+right;
                result.push_back(one);
            }
        }
        return result;
    }
};
