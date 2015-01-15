class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret;
        unordered_map<int, int> mapping;
        for (int i = 0; i != numbers.size(); ++i){
            int a = numbers[i];
            if (mapping.count(a) > 0){
                ret.push_back(mapping[a] + 1);
                ret.push_back(i + 1);
                return ret;
            }
            mapping[target - a] = i;
        }
    }
};
