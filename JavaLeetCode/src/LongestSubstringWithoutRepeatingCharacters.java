import java.util.HashMap;
import java.util.Scanner;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s == "")
        {
            return 0;
        }
        if (s == " ")
        {
            return 1;
        }
        int len=s.length();
        int maxLen=0;
        int []index=new int[128];
        int i=0,j=0;
        for (;j<len;j++)
        {
            i=Math.max(index[s.charAt(j)],i);
            maxLen=Math.max(maxLen,j-i+1);
            index[s.charAt(j)]=j+1;
        }

        return maxLen;
//        HashMap<Character,Integer> hashMap=new HashMap<>();
//        int start=0,end=0;
//        int maxLen = 0;
//        for (;end<s.length();)
//        {
//
//            if (hashMap.get(s.charAt(end))!=null&&hashMap.get(s.charAt(end))>=start)
//            {
//                start=hashMap.get(s.charAt(end))+1;
//            }
//            else
//            {
//                hashMap.put(s.charAt(end),end);
//                end++;
//                int sLen = end - start;
//                if (sLen > maxLen)
//                {
//                    maxLen = sLen;
//                }
//            }
//        }
//        return maxLen;
    }
}

public class LongestSubstringWithoutRepeatingCharacters {
    public static void main(String[] args) {
        while (true)
        {
            Scanner in=new Scanner(System.in);
            System.out.println("please input a String ");
            String s=in.nextLine();
            Solution solution=new Solution();
            System.out.println(solution.lengthOfLongestSubstring(s));
        }
    }
}
