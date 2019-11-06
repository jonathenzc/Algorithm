package org.ironman.base.playground.leetcode;

public class Solution {

    public static void main(String[] args) {
        System.out.println(String.format("[%s]", toGoatLatin("I speak Goat Latin")));
        System.out.println(String.format("[%s]", toGoatLatin("The quick brown fox jumped over the lazy dog")));
    }

    private static String toGoatLatin(String S) {
        StringBuilder sb = new StringBuilder();
        String target = " " + S + " ";
        int preSpaceIdx = 0;
        int cnt = 1;
        while (preSpaceIdx < target.length() - 1) {
            int nextSpaceIdx = target.indexOf(" ", preSpaceIdx + 1);
            if (isVowelIgnoreCase(target.charAt(preSpaceIdx + 1))) {
                sb.append(target, preSpaceIdx + 1, nextSpaceIdx);
            } else {
                sb.append(target, preSpaceIdx + 2, nextSpaceIdx).append(target.charAt(preSpaceIdx + 1));
            }

            sb.append("ma");
            for (int i = 0; i < cnt; i++) {
                sb.append("a");
            }
            sb.append(" ");
            cnt++;
            preSpaceIdx = nextSpaceIdx;
        }


        return sb.substring(0, sb.length() - 1);
    }

    private static boolean isVowelIgnoreCase(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
}