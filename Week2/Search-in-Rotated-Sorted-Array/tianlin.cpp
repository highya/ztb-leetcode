class Solution {
public:
    int search(int A[], int n, int target) {
        int num = n;
        int position_head = 0;
        int position_tail = num-1;
        bool isHead = false;
        if(A[position_head] == target)
            return position_head;
        if(A[position_head] < target)
            isHead = true;
        position_head++;
        while(position_head <= position_tail){
            if(position_head == position_tail){
                if(target == A[position_head])
                    return position_head;
                break;
            }
            int pos = (position_head + position_tail)/2;
            if(A[pos] == target)
                return pos;
            else if(A[pos] < target && A[pos] >= A[0])
                position_head = pos+1;
            else if(A[pos] < target && A[pos] < A[0] && !isHead)
                position_head = pos+1;
            else if(A[pos] < target && A[pos] < A[0] && isHead)
                position_tail = pos-1;
            else if(A[pos] > target && A[pos] <= A[0])
                position_tail = pos-1;
            else if(A[pos] > target && A[pos] > A[0] && !isHead)
                position_head = pos+1;
            else if(A[pos] > target && A[pos] > A[0] && isHead)
                position_tail = pos-1;
            else
                position_head = pos+1;
        }
        return -1;
    }
};
