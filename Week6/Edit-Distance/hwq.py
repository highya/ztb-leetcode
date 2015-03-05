class Solution:
    # @return an integer
    def minDistance(self, word1, word2):
        s1=list(word1);l1=len(s1)
        s2=list(word2);l2=len(s2)
        opt=[[]for i in range(l1+1)]
        for i in range(l1+1):opt[i].append(i)
        for j in range(1,l2+1):opt[0].append(j)
        for i in range(l1):
            for j in range(l2):
                if s1[i]==s2[j]:
                    opt[i+1].append(opt[i][j])
                else:
                    opt[i+1].append(1+min(opt[i][j],opt[i+1][j],opt[i][j+1]))
        return opt[l1][l2]
