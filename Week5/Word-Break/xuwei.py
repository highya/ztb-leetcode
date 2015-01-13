class Solution:
    # @param s, a string
    # @param dict, a set of string
    # @return a boolean
    def wordBreak(self, s, dict):
        if s == "":
            return True
        dct = {}
        lenth = len(s)
        dct[0] = True
        for i in range(1,lenth+1):
            dct[i] = False
            for j in range(i-1,-1,-1):
                if dct[j] and (s[j:i] in dict):
                    dct[i] = True
                    break
        return dct[lenth]
