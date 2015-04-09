class Solution {
public:
    int changeToInt(string a){
        std::string::iterator it = a.begin();
        int num = 0;
		bool flag = false;
        while(it != a.end()){
            if(*it == '-')
			    flag = true;
            else
                num = 10*num + *it - '0';
            it++;
        }
        return flag ? -num : num;
    }
    int evalRPN(vector<string> &tokens) {
        int length = tokens.size();
        stack<int> record;
        for(int i=0;i<length;i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int num1 = record.top();
                record.pop();
                int num2 = record.top();
                record.pop();
                int num = 0;
                if(tokens[i] == "+")
                    record.push(num2+num1);
                else if(tokens[i] == "-")
                    record.push(num2-num1);
                else if(tokens[i] == "*")
                    record.push(num2*num1);
                else
                    record.push(num2/num1);
            }
            else
                record.push(changeToInt(tokens[i]));
        }
        return record.top();
    }
};
