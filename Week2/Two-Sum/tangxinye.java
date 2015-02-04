public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] result=new int[2];
        int tmp;
        HashMap<Integer,Integer> map=new HashMap<Integer,Integer>();
        for(int i=0;i<numbers.length;i++){
            map.put(numbers[i],i);
        }
        for(int i=numbers.length-1;i>=0;i--){
            tmp=target-numbers[i];
            if(map.containsKey(tmp)&&map.get(tmp)!=i){
                if(map.get(tmp)>i){
                    result[0]=i+1;
                    result[1]=map.get(tmp)+1;
                }else{
                    result[0]=map.get(tmp)+1;
                    result[1]=i+1; 
                }
                
            }
        }
        return result;
    }
}
