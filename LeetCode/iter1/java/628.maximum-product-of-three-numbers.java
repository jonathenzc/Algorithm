package org.ironman.base.playground.leetcode;

public class Solution {

    public static void main(String[] args) {
        int[] nums1 = new int[]{3, 1, 4, 1, 5};
        int[] nums2 = new int[]{1, 2, 3, 4, 5};
        int[] nums3 = new int[]{1, 2, 3, 4};
        int[] nums4 = new int[]{1, 2, 3};
        int[] nums5 = new int[]{-1, -2, -3};
        int[] nums6 = new int[]{-1000, -1000, 1000};
        int[] nums7 = new int[]{4, 3, 2, 1, -1, -5, -10, -4, -6, -4, -20};

        System.out.println(maximumProduct(nums1)); //60
        System.out.println(maximumProduct(nums2)); //60
        System.out.println(maximumProduct(nums3)); //24
        System.out.println(maximumProduct(nums4)); //6
        System.out.println(maximumProduct(nums5)); //-6
        System.out.println(maximumProduct(nums6)); //1000000000
        System.out.println(maximumProduct(nums7)); //800
    }

    public static int maximumProduct(int[] nums) {
        int max1 = Integer.MIN_VALUE, max2 = Integer.MIN_VALUE, max3 = Integer.MIN_VALUE;
        int min1 = Integer.MAX_VALUE, min2 = Integer.MAX_VALUE;

        for (int num : nums) {
            if (num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if (num > max2) {
                max3 = max2;
                max2 = num;
            } else if (num > max3) {
                max3 = num;
            }

            if (num < min1) {
                min2 = min1;
                min1 = num;
            } else if (num < min2) {
                min2 = num;
            }
        }

        return Math.max(max1 * max2 * max3, min1 * min2 * max1);
    }

}