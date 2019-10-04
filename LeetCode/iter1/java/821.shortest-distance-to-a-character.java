package org.ironman.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {

    public static int[] shortestToChar(String S, char C) {
        List<Integer> cIdxLst = new ArrayList<>();
        cIdxLst.add(Integer.MAX_VALUE);
        for (int i = 0; i < S.length(); i++) {
            if (S.charAt(i) == C) {
                cIdxLst.add(i);
            }
        }
        cIdxLst.add(Integer.MAX_VALUE);

        int[] ret = new int[S.length()];
        int cIdx = 1, preCIdx = cIdxLst.get(0), curCIdx = cIdxLst.get(cIdx);
        for (int i = 0; i < S.length(); i++) {
            if (i > curCIdx) {
                preCIdx = curCIdx;
                curCIdx = cIdxLst.get(++cIdx);
            }
            ret[i] = Math.min(Math.abs(preCIdx - i), Math.abs(curCIdx - i));
        }

        return ret;
    }

    public static void main(String[] args) {
        String S = "loveleetcode";
        char C = 'e';
        System.out.println(Arrays.toString(shortestToChar(S, C)));
    }
}