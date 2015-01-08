class LRUCache:
    def __init__(self, capacity):
        self.lst=[]
        self.dct={}
        self.cap=capacity

    def get(self, key):
        if key in self.dct:
            self.lst.remove([key,self.dct[key]])
            self.lst.append([key,self.dct[key]])
            return self.dct[key]
        else:
            return -1

    def set(self, key, value):
        if key in self.dct:
            self.lst.remove([key,self.dct[key]])
            self.dct[key] = value
            self.lst.append([key,self.dct[key]])
        else:
            if len(self.lst) == self.cap:
                del self.dct[self.lst[0][0]]
                del self.lst[0]
            self.dct[key] = value
            self.lst.append([key,self.dct[key]])
