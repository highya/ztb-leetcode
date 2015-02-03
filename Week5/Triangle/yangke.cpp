class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
    	int n=triangle.size();
    	vector<int> v;
    	for(int j=0;j<(int)triangle[n-1].size();j++)
    	{
    		v.push_back(triangle[n-1][j]);
    	}
    	for(int i=n-2;i>-1;i--)
    	{
    		vector<int> tmp(i+1,0);
    		for(int j=0;j<(int)triangle[i].size();j++)
    		{
    			if(triangle[i][j]+v[j]<triangle[i][j]+v[j+1])
    			{
    				tmp[j]=triangle[i][j]+v[j];
    			}else{
    				tmp[j]=triangle[i][j]+v[j+1];
    			}
    		}
    		v=tmp;
    	}
    	return v[0];
    }
};
