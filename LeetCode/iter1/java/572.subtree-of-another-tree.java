package org.ironman.base.playground.leetcode;

public class Solution {

    public static void main(String[] args) {
        testCase1();
        testCase2();
    }

    private static void testCase1() {
        TreeNode s1 = new TreeNode(1);
        TreeNode s2 = new TreeNode(2);
        TreeNode s3 = new TreeNode(3);
        TreeNode s4 = new TreeNode(4);
        TreeNode s5 = new TreeNode(5);

        s4.left = s1;
        s4.right = s2;
        s3.left = s4;
        s3.right = s5;

        TreeNode t1 = new TreeNode(1);
        TreeNode t2 = new TreeNode(2);
        TreeNode t4 = new TreeNode(4);
        t4.left = t1;
        t4.right = t2;

        System.out.println(isSubtree(s3, t4));
    }

    private static void testCase2() {
        TreeNode s0 = new TreeNode(0);
        TreeNode s1 = new TreeNode(1);
        TreeNode s2 = new TreeNode(2);
        TreeNode s3 = new TreeNode(3);
        TreeNode s4 = new TreeNode(4);
        TreeNode s5 = new TreeNode(5);

        s2.left = s0;
        s4.left = s1;
        s4.right = s2;
        s3.left = s4;
        s3.right = s5;

        TreeNode t1 = new TreeNode(1);
        TreeNode t2 = new TreeNode(2);
        TreeNode t4 = new TreeNode(4);
        t4.left = t1;
        t4.right = t2;

        System.out.println(isSubtree(s3, t4));
    }

    public static boolean isSubtree(TreeNode s, TreeNode t) {
        if (s == null && t == null) {
            return true;
        }

        if (s == null || t == null) {
            return false;
        }

        return matchHelper(s, t) || isSubtree(s.left, t) || isSubtree(s.right, t);
    }

    private static boolean matchHelper(TreeNode s, TreeNode t) {
        if (s == null && t == null) {
            return true;
        }

        if (s == null || t == null) {
            return false;
        }

        if (s.val == t.val) {
            return matchHelper(s.left, t.left) && matchHelper(s.right, t.right);
        }

        return false;
    }


    static public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }
}