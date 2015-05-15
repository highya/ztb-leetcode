class Solution {
public:
    int atoi(string str) {
        if(str == "") {
            return 0;
        }  
        int size = str.size();
        int sig = 1, i = 0, res = 0;
        int preffix = INT_MAX / 10, upper = preffix * 10;
        while(i < size && str[i] == ' ') {
            i++;
        }
        if(str[i] == '+' || str[i] == '-') {
           sig = str[i] == '+' ? 1 : -1;
           i++;
        }   
        for(; i<size && isdigit(str[i]); i++) {
            if(res <= preffix) {
                res *= 10;
                if(res != upper || INT_MAX - res >= str[i] - '0') {
                    res += str[i] - '0';
                }    
                else {
                    return sig == 1 ? INT_MAX : INT_MIN;
                }
            }    
            else {
                return sig == 1 ? INT_MAX : INT_MIN;
            }
        } 
        return res * sig;
    }
};
