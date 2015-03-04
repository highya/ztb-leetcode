public class Solution {
    public boolean isPalindrome(String s) {
        s=s.replaceAll("[^0-9a-zA-Z]","");
        s=s.toLowerCase();
        StringBuffer sb=new StringBuffer(s);
        String s2=sb.reverse().toString();
        return s.equals(s2);
    }
}
