class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(),num.end(),compare);
        int result = 0;
        int sum = 0;
        int size = num.size();
        int distance;
        int distance_abs = numeric_limits<int>::max();
        for(int i = 0;i < size - 2;i++)
        {
            if( (i > 0) && (num[i] == num[i - 1]) )
                continue;
            int j = i + 1;
            int k = size - 1;
            while (j < k)
            {
                   if( (j > i + 1) && (num[j] == num[j - 1]) )
                    {
                    	j++;
                    	continue;
                    }
                 if( (k < size - 1) && (num[k] == num[k + 1]) )
                 	{
                 		k--;
                       continue;
                  }
                 sum = num[i] + num[j] + num[k];
                 distance = sum - target;
                 if(distance == 0)
                 {
                     result = sum;
                     return result;
                 }
                 else if(distance < 0)
                 {
                     if(abs(distance) < distance_abs)
                     {
                         distance_abs = abs(distance);
                         result = sum;
                     }
                     j++;
                 }
                 else 
                 {
                     if(abs(distance) < distance_abs)
                     {
                         distance_abs = abs(distance);
                         result = sum;
                     }
                     k--;
                 }
            }
        }
        return result;
    }
    static bool compare(int a,int b)
    {
        return a < b;
    }
};
