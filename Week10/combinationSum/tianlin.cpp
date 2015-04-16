class Solution {
public:
    void dealWithIt(vector<int> list, int add_num_index, int target_left, vector<vector<int> >& result, vector<int> &candidates){
        if(candidates[add_num_index] > target_left)
            return;
        else if(candidates[add_num_index] == target_left){
            list.push_back(candidates[add_num_index]);
            result.push_back(list);
            return;
        }
        list.push_back(candidates[add_num_index]);
        for(int j=add_num_index;j<candidates.size();j++)
            dealWithIt(list, j, target_left-candidates[add_num_index], result,candidates);
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        int length = candidates.size() ;
        sort(candidates.begin(),candidates.end());
        vector<vector<int> > result;
        vector<int> list;
        for(int i=0;i<length;i++)
            dealWithIt(list, i, target, result,candidates);
		return result;
    }
};
