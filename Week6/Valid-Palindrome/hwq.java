public class Solution {
    public boolean isPalindrome(String s) {
        s=s.toLowerCase();
        char a[]=s.toCharArray();
        StringBuffer sb=new StringBuffer();
        for(int i=0;i<a.length;i++){
            if(Character.isLetterOrDigit(a[i])){
                sb.append(a[i]);
            }
        }
        String s1=sb.toString();
        String s2=sb.reverse().toString();
        return s1.equals(s2);
    }
}
