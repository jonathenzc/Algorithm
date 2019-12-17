package org.ironman.base.playground.leetcode;

import java.util.ArrayList;
import java.util.List;

public class Solution {

    public static void main(String[] args) {
        System.out.println(selfDividingNumbers(1, 22));
    }

    public static List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> ret = new ArrayList<>();
        for (int i = left; i <= right; i++) {
            if (whetherSelfDividing(i)) {
                ret.add(i);
            }
        }

        return ret;
    }

    private static boolean whetherSelfDividing(int num) {
        if (num == 0) {
            return false;
        }
        boolean ret = true;
        int tmpNum = num, digit;
        while (tmpNum != 0) {
            digit = tmpNum % 10;
            tmpNum /= 10;
            if (digit == 0 || num % digit != 0) {
                ret = false;
                break;
            }
        }

        return ret;
    }
}