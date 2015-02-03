public class Solution {
    public boolean wordBreak(String s, Set<String> dict) {
        if(s.equals("")) return false;
        int len = s.length();
        boolean[] subdict=new boolean[len+1];
        subdict[0]=true;
        String sub;
        for(int i = 1;i<=len;i++){
            subdict[i]=false;
            for(int j = 0;j<i;j++){
                sub=s.substring(j,i);
                if(subdict[j]&&dict.contains(sub)){
                    subdict[i]=true;
                    break;
                } 
            }
        }
        return subdict[len];
    }
}
