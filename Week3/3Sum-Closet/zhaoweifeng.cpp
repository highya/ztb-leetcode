class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(),num.end());
        
        int ans = num[0] + num[1] + num[2];
        int min = abs(ans-target);
        int tmp;
        
        for(vector<int>::size_type i=0;i<num.size()-2;i++) {
            for(vector<int>::size_type k=i+1,j=num.size()-1;k<j;) {
                tmp = num[i] + num[k] + num[j];
                if( min > abs(tmp-target)) {
                    min = abs(tmp-target);
                    if(min==0) return tmp;
                    else ans = tmp;
                }
                
                if(tmp < target) k++;
                else j--;
            }
        }
        
        return ans;
    }
};
