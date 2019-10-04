package org.ironman.leetcode;

import java.util.Arrays;

public class Main {

    public static int triangleNumber(int[] nums) {
        Arrays.sort(nums);
        int cnt = 0;
        int l, r;
        for (int i = nums.length - 1; i >= 2; i--) {
            l = 0;
            r = i - 1;
            while (l < r) {
                if (nums[l] + nums[r] > nums[i]) {
                    cnt += r - l; //if nums[l]+nums[r] > nums[i], then nums[l+1] or nums[l+2] + nums[r] > nums[i]
                    r--;
                } else {
                    l++;
                }
            }
        }
        return cnt;
    }

    public static void main(String[] args) {
        int[] nums = new int[]{2, 2, 3, 4};
        System.out.println(triangleNumber(nums));
    }
}
