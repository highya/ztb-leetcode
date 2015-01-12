class Solution {
public:
    int trap(int A[], int n) {
        int former = 0;
        int latter = n-1;
        int total = 0;
    	int current = (A[former]-A[latter]>0) ? A[latter] : A[former];
    	bool forward = (A[former]-A[latter]>0) ? false : true;
    	while(latter > former){
            if(!forward && A[latter-1] <= current){
                total = total + current - A[latter-1];
    			      latter--;
            }
            else if(!forward && A[latter-1] > current && A[latter-1] <= A[former]){
                latter--;
    			      current = A[latter];
            }
            else if(!forward && A[latter-1] > current && A[latter-1] > A[former]){
                latter--;
    			      current = A[former];
    			      forward = true;
            }
            else if(forward && A[former+1] >= current && A[former+1] <= A[latter]){
                former++;
    			      current = A[former];
            }
            else if(forward && A[former+1] >= current && A[former+1] > A[latter]){
                former++;
    			      current = A[latter];
    			      forward = false;
            }
            else if(forward && A[former+1] < current){
                total = total + current - A[former+1];
                former++;
            }
        }
        return total;
    }
};
