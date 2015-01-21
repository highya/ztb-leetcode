class Solution {
public:
    int getDifference(int a,int b)
        return (a>b) ? (a-b) : (b-a);
    int threeSumClosest(vector<int> &num, int target) {
        if(num.size()==0)   return 0;
        if(num.size()==1)   return *num.begin();
        if(num.size()==2)   return *num.begin()+*num.end();
    	sort(num.begin(),num.end());
        int sum = 999999999;
        vector<int>::iterator it_first,it_former,it_latter;
        for(it_first=num.begin(); it_first<=num.end()-3; it_first++){
            int target_tmp = target - *it_first;
            it_former = it_first+1;
            it_latter = num.end()-1;
            while(it_former < it_latter){
                if(getDifference((*it_former + *it_latter),target_tmp) < getDifference(sum,target))
                    sum = *it_former + *it_latter + *it_first;
                if((*it_former + *it_latter) == target_tmp)
                    return target;
                else if((*it_former + *it_latter) < target_tmp)
                    it_former++;
                else
                    it_latter--;
            }
        }
        return sum;
    }
};
