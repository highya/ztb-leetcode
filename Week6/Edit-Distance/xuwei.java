public class Solution {
    public int minDistance(String word1, String word2) {
        int word1Len = word1.length() , word2Len = word2.length();
        if(word1Len==0) return word2Len;
        if(word2Len==0) return word1Len;		
        int[][] edit = new int[word1Len+2][word2Len+2];
        for(int i=0;i<=word2Len;i++) edit[0][i] = i;
        for(int j=0;j<=word1Len;j++) edit[j][0] = j;
        int left,up,left_up;
        for(int i=1;i<=word1Len;i++){
            for(int j=1;j<=word2Len;j++){
                left = edit[i][j-1] + 1;
                up = edit[i-1][j] + 1;
                left_up = word1.charAt(i-1) == word2.charAt(j-1) ? edit[i-1][j-1]:edit[i-1][j-1]+1;
                edit[i][j] = Math.min(left,up) < left_up ? Math.min(left,up):left_up;
            }
        }
        return edit[i-1][j-1];
    }
}
