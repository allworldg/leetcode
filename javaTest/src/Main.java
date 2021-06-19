
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Stack;

/**
 * @Classname Main
 * @Description TODO
 * @Date 2021/6/2 11:39
 * @Created by 94493
 */
public class Main {
    public static void main(String[] args) {
       Solution solution = new Solution();
       int[] nums = {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
        System.out.println(solution.jump(nums));
    }
}
class Solution {
    public int jump(int[] nums) {
        if (nums.length < 2) {
            return 0;
        }
        int maxLenth = 0;
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (maxLenth < i + nums[i]) {
                maxLenth = i + nums[i];
                count++;
                if (maxLenth >= nums.length - 1) {
                    return count;
                }
            }
        }
        return count;
    }
}
