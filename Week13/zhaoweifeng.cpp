class Solution {
	bool GetLastWord(string s,string::size_type &rst,string &str) {
	    if(rst == string::npos) return false;
		string::size_type red = s.find_last_not_of(' ',rst);
		if(red == string::npos) return false;

		rst = s.find_last_of(' ',red);
		if(rst == string::npos) {
			str = s.substr(0,red+1);
		}
		else {
			str = s.substr(rst+1,red-rst);
		}

		str += " ";
		return true;
	}

public:
    void reverseWords(string &s) {
	    string res = "";
		string str;
		string::size_type rst = s.end()-s.begin()-1;

		while(GetLastWord(s,rst,str)) {
			res += str;
		}
		if(res.size() > 0 && res[res.size()-1]==' ') res.erase(res.size()-1,1);
		s=res;
    }
};

class Solution {
public:
    void reverseWords(string &s) {
		if(s.empty()) return;
		size_t pi=0,pj=0,i=0;
		bool res=true;
        
		string str;
		do {
			pi=s.find_first_not_of(' ',pj);
			if(pi==s.npos) res=false;
			else {
				pj=s.find_first_of(' ',pi);
				if(pj==s.npos) {
					pj=s.size();
				}
			}
			if(res) {
				str = s.substr(pi,pj-pi);
				reverse_copy(str.begin(),str.end(),s.begin()+i);
				i+=pj-pi;
				if(pj!=s.size()) s[i++]=' ';
			}
		}
        while(res);
 
		s.resize(i);
		if(s.back()==' ') s.resize(s.size()-1);
		reverse(s.begin(),s.end());
    }
};
