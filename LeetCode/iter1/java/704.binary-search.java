package org.ironman.base.playground.leetcode;

public class Solution {

    public static void main(String[] args) {
        int[] nums = new int[]{-1, 0, 3, 5, 9, 12};
        int i = -5;
        while (i < 20) {
            System.out.println(i + " " + search(nums, i));
            i++;
        }

    }

    public static int search(int[] nums, int target) {
        int start = 0, end = nums.length, mid = -1, targetIdx = -1;
        while (start < end) {
            mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                targetIdx = mid;
                break;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return targetIdx;
    }
}