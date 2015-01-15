class Solution {
public:
    int atoi(const char *str) {
        if (*str == '\0') return 0;
        while (*str == ' ') ++str;
        bool positive = true;
        if (*str == '+'){
            ++str;
        }else if (*str == '-'){
            ++str;
            positive = false;
        }
        if(!isNumber(*str)){
            return 0;
        }
        int result = *str++ - '0';
        while (isNumber(*str)){
            int digit = *str++ - '0';
            int tmp = result * 10 + digit;
            if (tmp < 0 || (tmp - digit) / 10 != result){
                if (positive) return INT_MAX;
                else return INT_MIN;
            }
            result = tmp;
        }
        if (!positive) result = -result;
        return result;
    }
    
    bool isNumber(char c){
        return (c >= '0' && c <= '9');
    }
};
