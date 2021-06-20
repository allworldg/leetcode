
import java.security.PublicKey;
import java.util.*;

/**
 * @Classname Main
 * @Description TODO
 * @Date 2021/6/2 11:39
 * @Created by 94493
 */
public class Main {
    public static void main(String[] args) {
        ArrayList<Integer> arrayList = new ArrayList<>();
        testArr(arrayList);
        System.out.println(arrayList.get(0));
    }

    static void testArr(ArrayList<Integer> arr) {
        arr.add(123);
    }
}

