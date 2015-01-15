class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        //hash_map不支持，若支持复杂度为O(1),用map替代，内部实现为平衡二叉树，查找复杂度O(logN),看有的参考答案也有用unordered_map,复杂度貌似是O(1)
        map<int, int> hmap;
        vector<int> result;
        for(int i = 0; i < numbers.size(); i++) {
            hmap[numbers[i]] = i;
        }
        
        for(int i = 0; i < numbers.size(); i++) {
            int num_to_find = target - numbers[i];
            if(hmap.find(num_to_find) != hmap.end()) {
                if(hmap[num_to_find] != i) { 
                    result.push_back(i + 1);
                    result.push_back(hmap[num_to_find] + 1);
                    return result;
                }
            }
        }
        return result;
    }
};
