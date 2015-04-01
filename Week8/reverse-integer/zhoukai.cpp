class Solution {
public:
    int reverse(int x) {
        int mol,sign;
        long result = 0;
        
        if(x == INT_MIN)
        return 0;
    
        if(x < 0) 
            sign =-1;
        else
            sign = 1;
        
        x=abs(x);
        
        while(x != 0){
            mol = x%10;
            result = result*10 + mol;
            x/=10;
        }
    

        if (result > 2147483647)
           return 0;
        
        return result*sign;
    
    }
};
