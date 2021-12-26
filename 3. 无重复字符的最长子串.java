import java.util.HashSet;


/**
 * 思路：设置两个指针lp和rp，遍历字符串，如果不含重复的则rp向右移动，同时记录不重复子串长度，遇到重复的则移动lp。
 */
class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character> set = new HashSet<>();
        int lp = 0;
        int rp = 0;
        int maxNum = 0;
        while(rp<=s.length()-1){
           if(!set.contains(s.charAt(rp))){
               set.add(s.charAt(rp));
               rp++;
               maxNum = Math.max(maxNum,rp-lp);
           }else{
               set.remove(s.charAt(lp));
               lp++;
           }
           
        }
        return maxNum;
    }
}