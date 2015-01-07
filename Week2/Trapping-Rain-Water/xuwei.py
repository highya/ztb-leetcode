#写的丑，求牛逼解法...
class Solution:
    def trap(self, A):
        if len(A)==0:
            return 0
        crest,water,B=[],0,[]
        B.append(0)
        B.append(A[0])
        for i in range(1,len(A)):
            if A[i]!=A[i-1]:
             B.append(A[i])
        B.append(0)
        for i in range(1,len(B)):
            if B[i]>B[i-1] and B[i]>B[i+1]:
                crest.append([B[i],i] )
        for i in range(1,len(crest)):
            height=min(crest[i][0],crest[i-1][0])
            length=crest[i][1]-crest[i-1][1]-1
            no_water=0
            for j in range(crest[i-1][1]+1,crest[i][1]):
                if B[j]>height:
                    B[j]=height
                no_water+=B[j]
            water+=height*length-no_water
        return water
