class Solution {
public:
    int atoi(const char A[]) {
    
    int length;
	int i,j;
	long long ans = 0 ,temp = 0 ;
	
	length = strlen(A);
	for (i =  0; i<= length -1; i++){										// 开始的空格不算
		if (A[i] == ' ') ;
		else break;
	}

	for(j = i; j< length; j++){
		if( (A[j-1] == '-' || A[j-1] == '+') && (A[j] < '0' || A[j] > '9') ) return 0;    			// ++，--， +或- 后面跟的是非法字符到情况，出错，返回0
		if((A[j-1]-'0' >= 0 && A[j-1]-'0' <= 9) && A[j] < '0' || A[j] > '9' ) {					// 已经读入数字，后面跟的任何非数字字符的情况，返回前面数字到结果
					if(A[i] == '-') ans = 0 - ans;
					if (ans > INT_MAX) return INT_MAX;
	                if (ans < INT_MIN) return INT_MIN;
					return (int)ans;
		}	
		if(A[j]-'0' >= 0 && A[j]-'0' <= 9) ans = ans*10 + (A[j]-'0');						// 正常情况，直接计算数字。
        
        temp = ans;
        
		if(A[i] == '-') temp = 0 - temp;
	    if (temp > INT_MAX) return INT_MAX;
	    if (temp < INT_MIN) return INT_MIN;
	}
											
	if(A[i] == '-') ans = 0 - ans;                  	//如果开始为-，变成负数
	if (ans > INT_MAX) return INT_MAX;
	if (ans < INT_MIN) return INT_MIN;
	return (int)ans;	
    }
};
