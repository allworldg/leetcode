/*
 * @lc app=leetcode.cn id=376 lang=java
 *
 * [376] 摆动序列
 */
/* 贪心算法
名词解释：
1、上升序列：1、3、5、7为上升序列
2、下降序列：7、5、3、1为下降序列
3、起始序列：完整序列起始部分到上升或者下降序列之前为起始序列。例如：0、0、1、2中，0、0为起始序列。
主要思路是当一段序列不是摇摆序列时，该序列中子序列上升序列和下降序列肯定可以组成子摇摆序列。所以贪心目的是要找到上升序列和下降序列中的尾部作为整个摇摆序列中部分，因为只有序列末端的数值才能尽可能大或者小，才能与下一段上升或者下降序列构成摇摆序列，而不会产生此序列末端和下一个序列的开头相等的情况。

作者：c_j
链接：https://leetcode-cn.com/problems/wiggle-subsequence/solution/zhi-xing-yong-shi-0-ms-zai-suo-you-java-g42ci/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。 */

// @lc code=start
class Solution {
    public int wiggleMaxLength(int[] nums) {
        if (nums.length < 2) {
            return nums.length;
        }
        int max = 1;
        final int begin = 0;
        final int up = 1;
        final int down = 2;
        int state = begin;
        for (int i = 1; i < nums.length; i++) {
            switch (state) {
                case begin:
                    if (nums[i] - nums[i - 1] > 0) {
                        state = up;
                        max++;
                    } else {
                        state = down;
                        max++;
                    }
                    break;
                case up:
                    if (nums[i] - nums[i - 1] < 0) {
                        state = down;
                        max++;
                    }
                    break;
                case down:
                    if (nums[i] - nums[i - 1] > 0) {
                        state = up;
                        max++;
                    }
            }
        }
        return max;
    }
}
// @lc code=end

