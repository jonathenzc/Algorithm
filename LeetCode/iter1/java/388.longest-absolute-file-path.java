package org.ironman.base.playground.leetcode;

import java.util.Stack;

public class Solution {

    public static void main(String[] args) {
        System.out.println(lengthLongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"));
        System.out.println(lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"));
    }

    public static int lengthLongestPath(String input) {
        String[] path = input.split("\n");
        Stack<Integer> stack = new Stack<>();
        int curLen = 0;
        int ret = 0;

        for (String s : path) {
            int level = s.lastIndexOf("\t") + 1;

            while (stack.size() > level) {
                curLen -= stack.pop();
            }

            //eg: /file.txt
            int pathLen = "/".length() + s.length() - level;
            curLen += pathLen;

            if (s.contains(".")) {
                ret = Math.max(ret, curLen - 1); //starter slash
            }

            stack.push(pathLen);
        }

        return ret;
    }
}