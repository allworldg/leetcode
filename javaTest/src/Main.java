
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
        int x = 628;
        int[] nums = {100,50,20,10,5,2,1};
        int i=0;
        int count = 0;
        int length = nums.length;
        while(i<length){
            int use = x/nums[i];
            count += use;
            x = x-use*nums[i];
            System.out.println("需要面额"+nums[i]+"，需要"+use+"张");
            i++;
            System.out.println("还剩"+x+"金额");
        }
        System.out.println(count);
    }
}
