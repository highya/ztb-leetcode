class Solution {
public:
    void nextPermutation(vector<int> &num) {     //只要序列中有升序就有提升值的空间
        if(num.size() <= 1)
            return;
        int index = num.size()-2,index_record = -1;
        while(index >= 0){
            if(num[index] < num[index+1]){
                index_record = index;
                break;
            }
			index--;
        }
        if(index_record > -1){
            while(index+1 <= num.size()-1 && num[index+1] > num[index_record]){
                index++;
            }
            swap(num[index],num[index_record]);
            reverse(num.begin()+index_record+1,num.end());
        }
        else
            reverse(num.begin(),num.end());
    }
};
