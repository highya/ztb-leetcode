class Solution {
public:
    int numTrees(int n) {
        if (n == 1) return 1;
        else if (n == 2) return 2;
        
        int *solved = new int[n + 1];
        solved[0] = solved[1] = 1;
        solved[2] = 2;
        for (int i = 3; i <= n; ++i){
            solved[i] = solve(solved, i);
        }
        
        int result = solved[n];
        delete[] solved;
        return result;
    }
    
    int solve(int solved[], int n){
        int result = 0;
        int left = 0;
        int right = n - 1;
        int half = n / 2;
        while (left < half){
            result += solved[left] * solved[right];
            left++;
            right--;
        }
        result *= 2;
        if (n % 2 != 0) result += solved[left] * solved[right];
        
        return result;
    }
};
