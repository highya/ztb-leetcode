class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(),num.end());
        int least=INT_MAX;
        int record;
        for(int i=0;i<num.size()-2;i++)
        {
            int r=find(num,target-num[i],i+1);
            if(r==target-num[i])
                return target;
            int ab=abs(target-num[i]-r);
            if(ab<least)
            {
                least=ab;
                record=num[i]+r;
            }
        }
        return record;
    }
    int find(vector<int> &num, int target,int m)
    {
        if(m>=num.size())return 0;
        int p=m;
        int q=num.size()-1;
        int least=INT_MAX;
        int record=0;
        while(p<q)
        {
            if(num[p]+num[q]<target)
            {
                int ab=abs(target-num[p]-num[q]);
                if(ab<least)
                {
                    least=ab;
                    record=num[p]+num[q];
                }
                p++;
            }else if(num[p]+num[q]>target)
            {
                int ab=abs(target-num[p]-num[q]);
                if(ab<least)
                {
                    least=ab;
                    record=num[p]+num[q];
                }
                q--;
            }else{
                return target;
            }
        }
        return record;
    }
};
