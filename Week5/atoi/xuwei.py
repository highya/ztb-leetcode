class Solution:
    # @return an integer
    def atoi(self,str):
        if str == "":
            return 0
        flag = 1
        str = str.strip()
        INT_MAX,INT_MIN = 2147483647,-2147483648
        if str[0] == "-" or str[0] == "+":
            if str[0] == "-":
                flag = -1
            str = str[1:]
        j,ret = 0,0
        if str[0].isdigit() == False:
            return 0
        for i in range(0,len(str)):
            if str[i].isdigit():
                ret = ret*10 + int(str[i])
                j = j + 1
            else:
                break
        if ret*flag > INT_MAX:
            return INT_MAX
        if ret*flag < INT_MIN:
            return INT_MIN
        return  ret*flag
