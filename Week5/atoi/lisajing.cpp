class Solution {
public:
    int atoi(const char *str) {
        long num = 0;
        long negative = 1;
        const char *p = str;
        if(str == '\0')
            return 0;
        while( (*p == '\t')||(*p == ' ')||(*p == '\n') )
            p++;
        if( (*p != '\0') || (p != NULL) )
        {
            if(*p == '-')
            {
                negative = -1;
                p++;
            }
            else if(*p == '+')
            {
                negative = 1;
                p++;
            }
            int i = 1;
            while(*p != '\0')
            {
                switch (*p)
                {
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        num = num * 10 + (*p - '0');
                        p++;
                        i++;
                        continue;
                    default:
                     if(i > 11)
                   		return (negative == 1)?(2147483647):(-2147483648);
                    if(num == 0) 
                    	 return 0;
                    if((negative>0) &&(num *negative > 2147483647) )
                           return 2147483647;
                 else if((negative < 0)&&(num *negative < -2147483648))
                    	{
                            return -2147483648;
                          }
                    else
                       return (int)(num * negative);
                }
              }
                 if(i > 11)
                   		return (negative == 1)?(2147483647):(-2147483648);
            	if(num == 0) 
                    	 return 0;
                 if((negative>0) &&(num *negative > 2147483647) )
                           return 2147483647;
                 else if((negative < 0)&&(num *negative < -2147483648))
                    	{
                            return -2147483648;
                          }
                    else
                       return (int)(num * negative);
           }
        else
              return 0;
        
    }
};
