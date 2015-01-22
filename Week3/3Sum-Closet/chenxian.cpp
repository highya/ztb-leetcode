class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        //先排序
        sort(num.begin(),num.end());
        int n=num.size();
        int dis=10000;
        int res=0;
        int j,k;
        
        //遍历最小的那个数，另两个XXX
        for(int i=0;i<n-2;i++){
            j=i+1;
            k=n-1;
            while(j<k){
                int temp=num[i]+num[j]+num[k]-target;
                if(temp>0){
                    k=k-1;
                    if(temp<dis){
                        dis=temp;
                        res=temp+target;
                    }
                }
                else{
                    j=j+1;
                    if(-temp<dis){
                        dis=-temp;
                        res=temp+target;
                    }
                }
            }
        }
        return res;
    }
};
