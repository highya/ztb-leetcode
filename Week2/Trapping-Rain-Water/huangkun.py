#谁看谁傻X
class Solution:
    # @param A, a list of integers
    # @return an integer
    
    def calLocalArea(self,A,s,e):
        minHeight=A[s] if A[s]<A[e] else A[e]
        distance=e-s-1
        filledArea=0
        if distance<0 :
            return 0
        i=s+1
        while i<e:
            filledArea=filledArea+A[i]
            i+=1
        return minHeight*distance-filledArea 
    def partition(self,A,s,e):
        if e-s<=1:
            return 0
        maxValIndex=self.getMaxValIndex(A,s,e)
        maxVal=A[maxValIndex] 
        secondValIndex=self.getSecondValIndex(A,s,e,maxVal,maxValIndex)      
        leftBorder,rightBorder=0,0 
        if maxValIndex < secondValIndex :
            leftBorder=maxValIndex
            rightBorder=secondValIndex
        elif maxValIndex > secondValIndex:
            leftBorder=secondValIndex
            rightBorder=maxValIndex
        else:
            print "error"
        currentArea=self.calLocalArea(A,leftBorder,rightBorder)
        return currentArea+self.partition(A,s,leftBorder)+self.partition(A,rightBorder,e)

    def getMaxValIndex(self,A,s,e):
        maxVal=-1
        maxValIndex=-1
        for i in range(s,e+1):
            if A[i] > maxVal :
                maxVal=A[i]
                maxValIndex=i
        return maxValIndex

    def getSecondValIndex(self,A,s,e,maxVal,maxValIndex):
        secondVal=-1
        secondIndex=-1 
        for i in range(s,e+1):
            if A[i] > secondVal and A[i]<=maxVal and i!=maxValIndex:
                secondIndex=i
                secondVal=A[i]
        return secondIndex

    def trap(self, A):
        return self.partition(A,0,len(A)-1)
