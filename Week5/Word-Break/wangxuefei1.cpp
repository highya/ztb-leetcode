class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(s.length() < 1) return true;  
        bool flag = false;  
        for(int i = 1; i <= s.length(); i++)  
        {  
            string tmpstr = s.substr(0,i);  
            unordered_set<string>::iterator it = dict.find(tmpstr);  
            if(it != dict.end())  
            {  
                if(tmpstr.length() == s.length())
                {
                  return true;  
                }
                flag = wordBreak(s.substr(i),dict);  
            }  
            if(flag)return true;  
        }  
        return false; 
    }
};
