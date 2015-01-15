class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int,int> hm;
        int index1,index2;
        int num=numbers.size();
        
        //创建map
        for(int i=0;i<num;i++){
            if(hm.find(target-numbers[i])!=hm.end()){
                if(2*numbers[i]==target)
                    return {hm[target-numbers[i]]+1,i+1};
            }
            else
                hm[numbers[i]]=i;
        }
        
        //在map中查找
        for(int i=0;i<num;i++){
            hm.erase(numbers[i]);
            if(hm.find(target-numbers[i])!=hm.end()){
                index1=i+1;
                index2=hm[target-numbers[i]]+1;
                break;
            }
            hm[numbers[i]]=i;
        }
        if(index1<index2)
            return {index1,index2};
        else
            return {index2,index1};
    }
};
