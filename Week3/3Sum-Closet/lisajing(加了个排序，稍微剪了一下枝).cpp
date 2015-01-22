class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int size = num.size();
        if (size == 0)   return 0;
        if (size == 1)   return num[0];
        if (size == 2)   return num[0] + num[1];
        int distance = 2147483647;
        int sum = 0;
        sort(num.begin(),num.end(),compare);
        for(int i = 0; i < size; i++)
        {
            if((i > 0)&&(num[i] == num[i - 1]))
                continue;
            for(int j = i + 1; j < size; j++)
            {
                if((j >  i + 1)&&(num[j] == num[j - 1]))
                    continue;
                for(int k = j + 1; k < size; k++)
                {
                    if((k > j + 1)&&(num[k] == num[k - 1]))
                        continue;
                    if (abs(num[i] + num[j] + num[k] - target) < distance )
                    {
                        distance = abs(num[i] + num[j] + num[k] - target);
                        sum = num[i] + num[j] + num[k];
                        if(distance == 0)
                            return sum;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
        }
        return sum;
    }
   static bool compare(int a,int b)
    {
        return a < b;
    }
};
