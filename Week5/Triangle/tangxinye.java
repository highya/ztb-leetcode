public class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        
        int lenAll = triangle.size();
        int[] helper = new int[lenAll];
        int min=Integer.MAX_VALUE;
        for(int m=0;m<lenAll;m++){
            helper[m]=0;
        }
        
        for(int i=0;i<lenAll;i++){
            int len = triangle.get(i).size();
            for(int j=len-1;j>=0;j--){
                if(j!=0&&j==len-1){
                    helper[j]=helper[j-1]+triangle.get(i).get(j);
                }else if(j==0){
                       helper[j]=helper[j]+triangle.get(i).get(j);
                }else{
                    helper[j]=(helper[j-1]<helper[j]?helper[j-1]:helper[j])+triangle.get(i).get(j);
                }
                if(i==lenAll-1 && helper[j]<min){
                    min=helper[j];
                }
            }
        }
        return min;
    }
}
