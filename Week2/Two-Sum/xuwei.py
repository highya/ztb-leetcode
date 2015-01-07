class Solution:
    # @return a tuple, (index1, index2)
    def twoSum(self, num, target):
        mmap={}
        for i in range(len(num)):
            if num[i] not in mmap:
                mmap[target-num[i]]=i
            else:
                return [mmap[num[i]]+1,i+1]
