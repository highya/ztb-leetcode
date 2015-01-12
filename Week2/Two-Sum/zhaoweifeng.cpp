class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ivec(2);
        int sub;
        map<int,int> numbmap;
        map<int,int>::iterator itmap;
        
        for(vector<int>::size_type i=0;i<numbers.size();i++)
        {
            sub = target - numbers[i];
            if(numbmap.find(sub) != numbmap.end())
            {
                ivec[0] = numbmap.find(sub)->second + 1;
                ivec[1] = i + 1;
                
                return ivec;
            }
            else
            {
                numbmap[numbers[i]] = i; 
            }
        }
        
        return ivec;
    }
};
