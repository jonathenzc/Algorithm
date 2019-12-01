package org.ironman.base.playground.leetcode;

import java.util.HashMap;
import java.util.Map;

public class Solution {

    public static void main(String[] args) {
        System.out.println(findShortestSubArray(new int[]{1, 2, 2, 3, 1}));
        System.out.println(findShortestSubArray(new int[]{1, 2, 2, 3, 1, 4, 2}));
        System.out.println(findShortestSubArray(new int[]{2, 3}));
        System.out.println(findShortestSubArray(new int[]{3}));
    }

    public static int findShortestSubArray(int[] nums) {
        Map<Integer, Integer> num2FirstIdx = new HashMap<>(), num2Cnt = new HashMap<>();
        int ret = Integer.MAX_VALUE, maxDegree = 0;

        for (int i = 0; i < nums.length; i++) {
            num2FirstIdx.putIfAbsent(nums[i], i);
            int cnt = num2Cnt.getOrDefault(nums[i], 0) + 1;
            num2Cnt.put(nums[i], cnt);

            if (maxDegree < cnt) {
                maxDegree = cnt;
                ret = i - num2FirstIdx.get(nums[i]) + 1;
            } else if (maxDegree == cnt) {
                ret = Math.min(ret, i - num2FirstIdx.get(nums[i]) + 1);
            }
        }

        return ret;
    }

}