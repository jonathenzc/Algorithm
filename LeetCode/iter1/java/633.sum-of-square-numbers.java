package org.ironman.base.playground.leetcode;

import java.util.HashSet;
import java.util.Set;

public class Solution {

    public static void main(String[] args) {
        System.out.println("0 " + judgeSquareSum(0));
        System.out.println("2 " + judgeSquareSum(2));
        System.out.println("3 " + judgeSquareSum(3));
        System.out.println("4 " + judgeSquareSum(4));
        System.out.println("5 " + judgeSquareSum(5));
        System.out.println("9 " + judgeSquareSum(9));
        System.out.println("147 " + judgeSquareSum(147));
        System.out.println(Integer.MAX_VALUE + " " + judgeSquareSum(Integer.MAX_VALUE));
    }

    public static boolean judgeSquareSum(int c) {
        int upperBound = (int) Math.sqrt(c);
        Set<Integer> squareSet = new HashSet<>();
        for (int i = 0; i <= upperBound; i++) {
            int iSquare = i * i;
            squareSet.add(iSquare);
            if (squareSet.contains(c - iSquare)) {
                return true;
            }
        }

        return false;
    }
}