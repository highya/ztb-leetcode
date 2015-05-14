class Solution {
public:
    void reverseWords(string &s) {
        stack<string> st;
        int i = 0;
        if(s.empty()) return ;
        while(i < s.size()) {
            string word;
            while(i < s.size() && s[i] == ' ')  i++;
            while(i < s.size() && s[i] != ' ') 
                word.push_back(s[i++]);
            if(word.size() != 0)
                st.push(word);
        }
        s.clear();
        while(!st.empty()) {
            string str = st.top();
            s = s + str + " ";
            st.pop();
        }
        if(!s.empty())
            s.erase(s.size()-1, 1);
    }
};
