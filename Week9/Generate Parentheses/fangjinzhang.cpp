class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n == 0) return result;
        generate(n - 1, n, "(", result);
        return result;
    }
    
    void generate(int left, int right, string s, vector<string> &result){
        if (left == 0 && right == 0){
            result.push_back(s);
            return;
        }
        
        if (left == right){
            generate(left - 1, right, s + "(", result);
        }else {
            if (left > 0) generate(left - 1, right, s + "(", result);
            generate(left, right - 1, s + ")", result);
        }
    }
};