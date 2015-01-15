class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        unordered_map<int,int> map;
        for(int i=0;i<numbers.size();i++)
        {
            map[numbers[i]]=i;
        }
        for(int i=0;i<numbers.size();i++)
        {
            int gap=target-numbers[i];
            if(map.find(gap)!=map.end() && map[gap]!=i)
            {
                result.push_back(i+1);
                result.push_back(map[gap]+1);
                return result;
            }
        }
    }
};
