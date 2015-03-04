class Solution:
    # @param s, a string
    # @return a boolean
    def isPalindrome(self, s):
        p = re.compile('[^0-9a-zA-Z]')
        s=p.sub('',s)
        s=s.lower()             
        c=s[::-1]
        return c==s
