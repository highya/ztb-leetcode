class Solution {
public:
    int reverse(int a) {
      long long b = 0;
      
	    while(a != 0){
		    b = b*10+ a %10;
	    	a = a/10;
	    }
	    if(b > 2147483647 || b < -2147483648) 
	      return 0;
	    else 
	      return (int)b;
  }
};
