class Solution {
public:
    int isValue(char a1,char a2){
        if(a2 == '*'){
            if(a1>='1' && a1<='9')
                return 1;
            return 0;
        }
        if((a1 == '1' && a2>='0' && a2<='9') || (a1 == '2' && a2>='0' && a2<='6'))
            return 1;
        return 0;
    }
    
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') {
            return 0;
        }
		char* p = (char*)s.c_str();
		int length = s.length();
		int index = 0;
		vector<int> record(length);     //重要的构造函数
        record[0] = 1;
        p++;
        index++;
        while(index < length){
            if(index == 1){
                if(isValue(*p,'*') && isValue(*(p-1),*p))
                     record[1] = 2;
                else if((!isValue(*p,'*') && isValue(*(p-1),*p)) || (isValue(*p,'*') && !isValue(*(p-1),*p)))
                     record[1] = 1;
				else
					 record[1] = 0;
				index++;
				p++;
				continue;
            }
            if(isValue(*p,'*'))
                record[index] += record[index-1];
            if(isValue(*(p-1),*p))
                record[index] += record[index-2];
			//cout << record[index] << "	"  << index<< endl;
			if(record[index] == 0 && record[index-1] == 0)
			    return 0;
			index++;
			p++;
        }
        return record[length-1];
    }
};
