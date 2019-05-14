package org.ironman;

import java.util.Arrays;

public class Main {

    //solution 1: using map
    public static int[] findErrorNums1(int[] nums) {
        int[] numMap = new int[nums.length + 1];
        for (int i = 0; i <= nums.length; i++) {
            numMap[i] = 1;
        }
        for (int num : nums) {
            numMap[num]--;
        }
        int duplicate = -1, missing = -1;
        int[] ret = new int[2];
        for (int i = 1; i <= nums.length; i++) {
            if (numMap[i] == -1) {
                duplicate = i;
            } else if (numMap[i] == 1) {
                missing = i;
            }
        }

        ret[0] = duplicate;
        ret[1] = missing;
        return ret;
    }

    //solution2: math
    public static int[] findErrorNums(int[] nums) {
        long[] sumDiff = {0, 0};
        for (int i = 1; i <= nums.length; i++) {
            sumDiff[0] += i - nums[i - 1];
            sumDiff[1] += i * i - nums[i - 1] * nums[i - 1];
        }

        //value1 = missing - duplicate
        //value2 = missing + duplicate
        long value1 = sumDiff[0], value2 = sumDiff[1] / sumDiff[0];

        int[] ret = new int[2];
        ret[0] = (int) (value2 - value1) / 2; //duplicate
        ret[1] = (int) (value1 + value2) / 2; //missing
        return ret;
    }

    public static void main(String[] args) {
        System.out.println("num1");
        int[] nums1 = new int[4];
        nums1[0] = 1;
        nums1[1] = 2;
        nums1[2] = 2;
        nums1[3] = 4;
        Arrays.stream(findErrorNums(nums1)).forEach(num -> System.out.println(num));

        System.out.println("num2");
        int[] nums2 = new int[6];
        nums2[0] = 1;
        nums2[1] = 2;
        nums2[2] = 2;
        nums2[3] = 3;
        nums2[4] = 4;
        nums2[5] = 5;
        Arrays.stream(findErrorNums(nums2)).forEach(num -> System.out.println(num));

    }
}
