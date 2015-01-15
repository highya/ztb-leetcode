class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int size = num.size();
        int diff = INT_MAX;
        int result;
        for (int i = 0; i < size - 2; ++i){
            int j = i + 1;
            int k = size - 1;
            while (k > j){
                int r = num[i] + num[j] + num[k];
                int d = abs(r - target);
                if (d == 0) return r;
                if (d < diff){
                    diff = d;
                    result = r;
                }
                if (r < target) ++j;
                else --k;
            }
        }
        return result;
    }
};
