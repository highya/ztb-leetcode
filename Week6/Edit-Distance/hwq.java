public class Solution {
    public int minDistance(String word1, String word2) {
        char s1[]=word1.toCharArray();int l1=s1.length;
        char s2[]=word2.toCharArray();int l2=s2.length;
        int opt[][]=new int[l1+1][l2+1];
        for(int i=0;i<l1+1;i++)opt[i][0]=i;
        for(int j=0;j<l2+1;j++)opt[0][j]=j;
        for(int i=0;i<l1;i++){
            for(int j=0;j<l2;j++){
                if(s1[i]==s2[j]){
                    opt[i+1][j+1]=opt[i][j];
                }else{
                    opt[i+1][j+1]=1+Math.min(opt[i][j],Math.min(opt[i+1][j],opt[i][j+1]));
                }
            }
        }
        return opt[l1][l2];
    }
}
