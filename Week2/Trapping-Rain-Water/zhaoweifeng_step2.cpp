class Solution {
public:
int trap(int A[], int n) {
  if(n<3) return 0;

	int volume=0,lmax=A[0],rmax=A[n-1];
	
	int i=0,j=n-1;
	
	while(i<=j) {
	    if(lmax<rmax) {
	        if(A[i]>lmax) lmax=A[i];
		    else {
			    volume += lmax - A[i];
		    }
		    i++;
	    }
	    else {
	        if(A[j]>rmax) rmax=A[j];
		    else {
			    volume += rmax - A[j];
		    }
		    j--;
	    }
	}

	return volume;
	}
};
