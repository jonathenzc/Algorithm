package org.ironman.base.playground.leetcode;

public class Solution {

    public static void main(String[] args) {
        System.out.println(validPalindrome("deeee"));
        System.out.println(validPalindrome("aba"));
        System.out.println(validPalindrome("abca"));
        System.out.println(validPalindrome("abcd"));
    }

    public static boolean validPalindrome(String s) {
        boolean ret = true;
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s.charAt(l) != s.charAt(r)) {
                ret = palindromeHelper(s, l + 1, r) || palindromeHelper(s, l, r - 1);
                break;
            }
            l++;
            r--;
        }

        return ret;
    }

    private static boolean palindromeHelper(String s, int l, int r) {
        boolean ret = true;
        while (l < r) {
            if (s.charAt(l++) != s.charAt(r--)) {
                ret = false;
                break;
            }
        }

        return ret;
    }

}