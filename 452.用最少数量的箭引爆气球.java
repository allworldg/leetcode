import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=452 lang=java
 *
 * [452] 用最少数量的箭引爆气球
 */
/* 贪心目标：射爆所有气球使用尽量少的箭，换言之就是一根箭尽量射到多的气球。
思路：最左侧的气球可以射中，要想尽可能射到第二个气球，则弓箭需要向右移动，同时不能移出最左侧气球的最右端，否则射中第二个气球的同时射不中第一个气球。所以可以得出结论，只需要每次找到一块区域的最左侧气球的最右端，如果找到一个气球的左侧大于这个最右端，说明需要新增箭头，则将新区域的最右端设置为新找到气球的最右端。
 */
// @lc code=start
class Solution {
    public int findMinArrowShots(int[][] points) {
        if (points.length == 0) {
            return 0;
        }
        Arrays.sort(points, (o1, o2) -> {
            if (o1[1] > o2[1]) {
                return 1;
            }
            else if (o1[1] < o2[1]) {
                return -1;
            }
            else {
                return 0;
            }
        });
        int position = points[0][1];//获得第一个最左侧的右边坐标
        int result = 1;//起码需要一根箭
        for (int[] ballon : points) {
            if (ballon[0] > position) {
                ++result;
                position = ballon[1];//更新右侧坐标
            }
        }
        return result;
    }
}
// @lc code=end

