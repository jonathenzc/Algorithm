package org.ironman.base.playground.leetcode;

import java.util.ArrayList;
import java.util.List;

public class Solution {

    public static void main(String[] args) {
        System.out.println(largeGroupPositions("aaa"));
        System.out.println(largeGroupPositions("abbxxxxzzy"));
        System.out.println(largeGroupPositions("abc"));
        System.out.println(largeGroupPositions("abcdddeeeeaabbbcd"));
    }

    public static List<List<Integer>> largeGroupPositions(String S) {
        S = S + " ";
        List<List<Integer>> ret = new ArrayList<>();

        char[] charArr = S.toCharArray();
        char preChar = charArr[0];
        int preIdx = 0;
        for (int i = 1; i < charArr.length; i++) {
            if (preChar == charArr[i]) {
                continue;
            }

            if (i - preIdx >= 3) {
                List<Integer> tmp = new ArrayList<>();
                tmp.add(preIdx);
                tmp.add(i - 1);
                ret.add(tmp);
            }

            preChar = charArr[i];
            preIdx = i;
        }

        return ret;
    }
}