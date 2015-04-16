class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        res.clear();
        dict.insert(start);  
        dict.insert(end);  
        vector<string> prev;  
        unordered_map<string, vector<string> > traces;  
        for (unordered_set<string>::const_iterator citr = dict.begin();   
                citr != dict.end(); citr++) {  
            traces[*citr] = prev;  
        }  
          
        unordered_set<string> cur,pre;  
        cur.insert(start);
        while (true) {  
           swap(cur,pre);
            for (unordered_set<string>::const_iterator citr = pre.begin();  
                    citr != pre.end(); citr++)  
                dict.erase(*citr);  
            cur.clear();  
            for (unordered_set<string>::const_iterator citr = pre.begin();  
                    citr != pre.end(); citr++) {  
                for (int n=0; n<(*citr).size(); n++) {    
                    string word = *citr;    
                    for (char ch='a';ch<='z';ch++) {
                        if(word[n]==ch) continue;
                        word[n]=ch;
                        if (dict.find(word) != dict.end()) {    
                            traces[word].push_back(*citr);  
                            cur.insert(word);   
                        }    
                    }  
                }  
            }  
            if (cur.size() == 0)  
                return res;  
            if (cur.count(end))  
                break;  
        }  
        vector<string> path;  
        buildPath(traces, path, end);  
        return res;
    }
private:
    vector<vector<string> >res;
    void buildPath(unordered_map<string,vector<string> >&traces,vector<string> &path,string &word)
    {
        if(traces[word].size()==0)
        {
            path.push_back(word);
            vector<string> curPath=path;
            reverse(curPath.begin(),curPath.end());
            res.push_back(curPath);
            path.pop_back();
            return;
        }
        vector<string> prevs=traces[word];
        path.push_back(word);
        for(vector<string>::iterator itr=prevs.begin();itr!=prevs.end();itr++)
        {
            buildPath(traces,path,*itr);
        }
        path.pop_back();
    }
};
