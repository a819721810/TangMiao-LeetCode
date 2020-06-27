public class LongestCommonPrefix {
    static class Solution {
        private String calculateLongestCommonPrefix(String str1, String str2) {
            String temp;
            int i = 0;
            for (; i < str1.length(); ) {
                if (str1.charAt(i)==str2.charAt(i)){
                    i++;
                }else {
                    break;
                }
            }
            temp=str1.substring(0,i);
            return temp;
        }

        public String longestCommonPrefix(String[] strs) {
            int len = strs.length;
            if (len == 0) {
                return "";
            }
            String result = strs[0];
            for (int i = 0; i < len; i++) {
                if (strs[i].length()>result.length()){
                    result=calculateLongestCommonPrefix(result,strs[i]);
                }else {
                    result=calculateLongestCommonPrefix(strs[i],result);
                }
                if (result.equals("")){
                    break;
                }
            }
            return result;
        }
    }

    public static void main(String[] args) {
        Solution s=new Solution();
        String[] strs={"flower","flow","flight"};
        System.out.println(s.longestCommonPrefix(strs));
    }
}
