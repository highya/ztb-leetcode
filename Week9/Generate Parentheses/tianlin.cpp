class Solution {
public:
    void generate(string& tmp,char a,int n_total,int n,vector<string>& record){
        tmp = tmp + a;
        if(tmp.length() == 2*n_total){
			if(a==')')
				record.push_back(tmp);
        }
        else if(tmp.length() > 2*(n_total-n));
        else{
            generate(tmp,')',n_total,n,record);
            if(n > 0)
                generate(tmp,'(',n_total,n-1,record);
        }
        tmp = tmp.substr(0,tmp.length()-1);
		if(tmp.length() == 2*n_total || tmp.length() > 2*(n_total-n))
			return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> record;
		if(n<=0)
            return record;
        string tmp = "";
        generate(tmp,'(',n,n-1,record);
		return record;
    }
};
