class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> sorted_numbers,results;
        int n = numbers.size();
        bool flag_first = true;
        int i;
        for(i=0;i<n;i++)
            sorted_numbers.push_back(numbers[i]);
        sort(sorted_numbers.begin(), sorted_numbers.end());
        int former = 0;
        int latter = n-1;
        while(latter > former){
            if(sorted_numbers[former] + sorted_numbers[latter] == target)
                break;
            else if(sorted_numbers[former] + sorted_numbers[latter] > target)
                latter = latter - 1;
            else
                former = former + 1;
        }
        for(i=0;i<n;i++)
            if(numbers[i] == sorted_numbers[former] || numbers[i] == sorted_numbers[latter])
                results.push_back(i+1);
        return results;
    }
};
