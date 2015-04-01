class Solution {
public:
    int reverse(int x) {
        bool flag = false;  //flag表示是否是负数
        long long newInt = 0;
        if(x<0){
            x = -x;
            flag = true;
        }
        while(x>0){
            int tmp = x%10;
            newInt = newInt*10 + tmp;
            x = x/10;
        }
        if(flag)
            newInt = (-1)*newInt;
        if(newInt>INT_MAX || newInt<INT_MIN)
            return 0;
        return newInt;
    }
};
