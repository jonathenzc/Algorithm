package org.ironman.base.playground.leetcode;

public class Solution {

    public static void main(String[] args) {
        System.out.println(findMaxAverage(new int[]{1, 12, -5, -6, 50, 4}, 4));
    }

    public static double findMaxAverage(int[] nums, int k) {
        double sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        double retMax = sum;
        for (int i = k; i < nums.length; i++) {
            sum += nums[i] - nums[i - k];
            retMax = Math.max(sum, retMax);
        }

        return retMax / k;
    }

}