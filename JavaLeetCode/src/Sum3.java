import java.util.*;

public class Sum3 {
    //    static class Solution {
//        private List<List<Integer>> oneResult(int[] nums, int target, int start) {
//            Map<Integer, Integer> restoreTwoSum = new HashMap<>();
//            List<List<Integer>> oneResult = new ArrayList<>();
//            for (int i = start; i < nums.length; i++) {
//                if (restoreTwoSum.containsKey(target - nums[i])) {
//                    List<Integer> tempList=new ArrayList<>();
//                    tempList.add(-target);
//                    tempList.add(target - nums[i]);
//                    tempList.add(nums[i]);
//                    Collections.sort(tempList);
//                    oneResult.add(tempList);
//                    continue;
//                }
//                restoreTwoSum.put(nums[i], nums[i]);
//            }
//
//            return oneResult;
//        }
//
//        public List<List<Integer>> threeSum(int[] nums) {
//            List<List<Integer>> resultList = new ArrayList<>();
//            Set<List<Integer>> resultSet = new HashSet<>();
//            for (int i = 0; i < nums.length; i++) {
//                List<List<Integer>> temp;
//                temp=oneResult(nums,-nums[i],i+1);
//                resultSet.addAll(temp);
//            }
//            resultList.addAll(resultSet);
//            return resultList;
//        }
//    }
    static class Solution {
        public List<List<Integer>> threeSum(int[] nums) {
            Arrays.sort(nums);
            List<List<Integer>> result = new ArrayList<>();
            final int len = nums.length;
            for (int i = 0; i < len; i++) {
                int first = i;
                if (first > 0 && nums[first] == nums[i - 1]) {
                    continue;
                }
                int second = i + 1;
                int third = len - 1;
                while (second < third) {
                    if (second > first + 1 && nums[second] == nums[second - 1]) {
                        second++;
                        continue;
                    }
                    if (nums[first] + nums[second] + nums[third] > 0) {
                        third--;
                    } else if (nums[first] + nums[second] + nums[third] < 0) {
                        second++;
                    } else {
                        List<Integer> temp = new ArrayList<>();
                        temp.add(nums[first]);
                        temp.add(nums[second]);
                        temp.add(nums[third]);
                        result.add(temp);
                        second++;
                        third--;
                    }
                }
            }
            return result;
        }
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = {-1, 0, 1, 2, -1, -4};
        System.out.println(s.threeSum(nums));
    }
}
