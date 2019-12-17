package org.ironman.base.playground.leetcode;

import java.util.PriorityQueue;

public class Solution {

    public static void main(String[] args) {
        int[] nums = new int[]{4, 5, 8, 2};
        KthLargest kthLargest = new KthLargest(3, nums);
        System.out.println(kthLargest.add(4));
        System.out.println(kthLargest.add(5));
        System.out.println(kthLargest.add(10));
        System.out.println(kthLargest.add(9));
        System.out.println(kthLargest.add(4));
    }

    static class KthLargest {

        private int kth;
        private PriorityQueue<Integer> minQ;

        public KthLargest(int k, int[] nums) {
            kth = k;
            minQ = new PriorityQueue<>(); //最小堆

            for (int i = 0; i < k && i < nums.length; i++) {
                minQ.add(nums[i]);
            }

            for (int i = k; i < nums.length; i++) {
                if (nums[i] > minQ.peek()) {
                    minQ.poll();
                    minQ.add(nums[i]);
                }
            }
        }

        public int add(int val) {
            if (minQ.size() < kth) {
                minQ.add(val);
            } else {
                if (val > minQ.peek()) {
                    minQ.poll();
                    minQ.add(val);
                }
            }
            return minQ.peek();
        }
    }
}