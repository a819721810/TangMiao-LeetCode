
public class ContainerWithMostWater {
    static class Solution {
        int calculateArea(int start, int end, int sHeight, int eHeight) {
            int len = end - start;
            int height = Math.min(sHeight, eHeight);
            return len * height;
        }

        public int maxArea(int[] height) {
            int maxLen = -1;
            int arrLen = height.length;
            for (int i = 0, j = arrLen - 1; i < arrLen; ) {
                if (i == j) {
                    return maxLen;
                }
                int area = calculateArea(i, j, height[i], height[j]);
                maxLen = Math.max(area, maxLen);
                if (height[i] > height[j]) {
                    j--;
                } else {
                    i++;
                }
            }

            return 0;
        }
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[] height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        System.out.println(s.maxArea(height));

    }
}
