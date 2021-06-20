
/* 思路：贪心，要想加油次数少，则每次都尽可能在油耗尽，同时加油要选加的最多。
方法：通过采用优先队列，存放每次路过的加油站，可以保证没油的时候能选择最大加油的加油站。 */
class Solution {
    public int minRefuelStops(int target, int startFuel, int[][] stations) {
        Queue<Integer> queue = new PriorityQueue<Integer>((o1, o2) -> {
            if (o1 > o2) {
                return -1;
            } else if (o1 < o2) {
                return 1;
            }
            return 0;
        });
        int count = 0;
        int pre = 0;//记录到下一个加油站所需要的路程
        for (int[] station : stations) {
            int location = station[0];//和目标之间的距离
            int capacity = station[1];//当前加油站的容量
            startFuel -= location - pre;//从上一个位置到达当前油站走过的路程需要扣油
            while (startFuel < 0 && !queue.isEmpty()) {
                startFuel += queue.poll();
                count++;
            }
            if (startFuel < 0) {
                return -1;
            }
            queue.offer(capacity);
            pre = location;
        }
          startFuel = startFuel - (target-pre);
        while (startFuel < 0 && !queue.isEmpty()) {
            startFuel += queue.poll();
            count++;
        }
        if (startFuel < 0) {
            return -1;
        }
        return count;
    }
}