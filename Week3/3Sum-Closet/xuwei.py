class Solution:
    def threeSumClosest(self, num, target):
        num.sort()
        res = float("inf")
        for i in range(len(num)-2):
            l,r = i+1,len(num)-1
            while l < r:
                sum = num[i] + num[l] + num[r]
                dis = target-sum
                if abs(dis) < abs(res):
                    res = dis
                if  dis == 0:
                    return target
                elif dis < 0:
                    r -= 1
                else:
                    l += 1
        return target-res
