class Solution {
public:
int trap(int A[], int n) {
	if(n<3) return 0;

	int volume=0,max=0,pos=0;

	for(int i=0;i<n;i++) 
	{
		if(A[i] > max) {
			max=A[i];
			pos=i;
		}
	}

	max=A[0];
	for(int i=1;i<pos;i++)
	{
		if(A[i]>max) max=A[i];
		else {
			volume += max - A[i];
		}
	}

	max=A[n-1];
	for(int i=n-1;i>pos;i--)
	{
		if(A[i]>max) max=A[i];
		else {
			volume += max - A[i];
		}
	}

	return volume;
	}
};
