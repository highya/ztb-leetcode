class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int index;
        map<int,int> record;
        vector<int> result;
        result.clear();
        for(index=0;index!=numbers.size();++index)
        {
            record[numbers[index]]=index;
        }
        for(index=0;index!=numbers.size();++index)
        {
            int rest=target-numbers[index];
            if(record.find(rest)!=record.end() && index<record[rest])
            {
                result.push_back(index+1);
                result.push_back(record[rest]+1);
                break;
            }
        }
        return result;
    }
};
