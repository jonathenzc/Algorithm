package org.ironman.base.playground.leetcode;

import java.util.ArrayList;
import java.util.List;

public class Solution {

    public static void main(String[] args) {
        System.out.println(diffWaysToCompute("2-1-1"));
        System.out.println(diffWaysToCompute("2*3-4*5"));
    }

    public static List<Integer> diffWaysToCompute(String input) {
        List<Integer> ret = new ArrayList<>();
        int num = str2int(input);
        if (num != -1) {
            ret.add(num);
            return ret;
        }

        for (int i = 0; i < input.length(); i++) {
            if (input.charAt(i) == '+' || input.charAt(i) == '-' || input.charAt(i) == '*') {
                List<Integer> leftLst = diffWaysToCompute(input.substring(0, i));
                List<Integer> rightLst = diffWaysToCompute(input.substring(i + 1));
                for (int leftVal : leftLst) {
                    for (int rightVal : rightLst) {
                        if (input.charAt(i) == '+') {
                            ret.add(leftVal + rightVal);
                        } else if (input.charAt(i) == '-') {
                            ret.add(leftVal - rightVal);
                        } else if (input.charAt(i) == '*') {
                            ret.add(leftVal * rightVal);
                        }
                    }
                }
            }
        }

        return ret;
    }

    private static int str2int(String input) {
        int ret = 0, digit = 1;
        for (int i = input.length() - 1; i >= 0; i--) {
            if (input.charAt(i) < '0' || input.charAt(i) > '9') {
                ret = -1;
                break;
            }

            ret += digit * (input.charAt(i) - '0');
            digit *= 10;
        }

        return ret;
    }
}