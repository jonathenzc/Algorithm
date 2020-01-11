package org.ironman.base.playground.leetcode;

public class Solution {

    public static void main(String[] args) {
        testCase1();
        testCase2();
    }

    private static void testCase1() {
        TreeNode s0 = new TreeNode(0);
        TreeNode s1 = new TreeNode(1);
        TreeNode s2 = new TreeNode(2);

        s0.left = s1;
        s0.right = s2;

        System.out.println(trimBST(s0, 1,2));
    }

    private static void testCase2() {
    }

    public static TreeNode trimBST(TreeNode root, int L, int R) {
        if(root == null) {
            return null;
        }

        if(root.val < L) {
            return trimBST(root.right, L, R);
        }

        if(root.val > R) {
            return trimBST(root.left, L, R);
        }

        root.left = trimBST(root.left, L, R);
        root.right = trimBST(root.right, L, R);

        return root;
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