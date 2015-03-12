public class Solution {
    public int minDistance(String word1, String word2) {
        if(word1==null){
            return word2.length();
        }
        if(word2==null){
            return word1.length();
        }
        int row=word1.length()+1;
        int column=word2.length()+1;
        int[][]rst=new int [row][column];
        for(int i=1;i<row;i++){
            for(int j=1;j<column;j++){
                rst[i][j]=Integer.MAX_VALUE;
            }      
        }
        for(int i=0;i<row;i++){
            rst[i][0]=i; 
        }
        for(int j=1;j<column;j++){
            rst[0][j]=j;   
        }
        for(int i=1;i<row;i++){
            for(int j=1;j<column;j++){
                if(word1.charAt(i-1)==word2.charAt(j-1)){
                    rst[i][j]=rst[i-1][j-1];
                }else{
                    rst[i][j]=rst[i-1][j-1]>rst[i-1][j]?rst[i-1][j]+1:rst[i-1][j-1]+1;
                    rst[i][j]=rst[i][j]>rst[i][j-1]?rst[i][j-1]+1:rst[i][j];
                }
            }
        }
        return rst[row-1][column-1];
    }
}
