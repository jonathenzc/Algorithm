package org.ironman.base.playground.leetcode;

public class Solution {

    public static void main(String[] args) {
        for (int i = 0; i < 30; i++) {
            System.out.println(i + " " + hasAlternatingBits(i));
        }
    }

    public static boolean hasAlternatingBits(int n) {
        boolean ret = true;
        int curDigit = n & 1, preDigit = curDigit;

        while (n != 0) {
            n = n >> 1;
            curDigit = n & 1;
            if (curDigit == preDigit) {
                ret = false;
                break;
            }

            preDigit = curDigit;
        }

        return ret;
    }

}