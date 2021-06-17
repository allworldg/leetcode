import java.util.ArrayList;

/*
 * @lc app=leetcode.cn id=295 lang=java
 *
 * [295] 数据流的中位数
 */

// @lc code=start
class MedianFinder {
    ArrayList<Integer> arrayList = new ArrayList<>();
    /** initialize your data structure here. */
    public MedianFinder() {

    }
    
    public void addNum(int num) {
        arrayList.add(num);
        arrayList.sort((o1, o2) -> o1 - o2);
    }
    
    public double findMedian() {
        if (arrayList.size() % 2 == 0) {
            return (arrayList.get(arrayList.size() / 2) + arrayList.get(arrayList.size() / 2 + 1)) / 2;
        }
        return arrayList.get(arrayList.size() / 2);
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
// @lc code=end

