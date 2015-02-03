public class Solution {
    public int atoi(String str) {
        str = str.trim();
        if(str.equals("")){
            return 0;
        }
        int ifMinus =  1;
        if(str.charAt(0)=='-'){
            ifMinus = -1;
            str = str.substring(1);
        }else if(str.charAt(0)=='+'){
            str = str.substring(1);
        }
        
        int len = str.length();
        long result = 0;
        for(int i = 0; i<len&&str.charAt(i)<='9'&&str.charAt(i)>='0';i++){
            result=result*10+str.charAt(i)-'0';
            if (result*ifMinus > Integer.MAX_VALUE)
                return Integer.MAX_VALUE;
	        if (result*ifMinus < Integer.MIN_VALUE)
	            return Integer.MIN_VALUE;
        }
        return (int)result*ifMinus;
    }
}
