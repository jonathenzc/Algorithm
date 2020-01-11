package org.ironman.base.playground.leetcode;

public class Solution {

    public static void main(String[] args) {
        testCase1();
        testCase2();
    }

    private static void testCase1() {
        TreeNode s0 = new TreeNode(2);
        TreeNode s1 = new TreeNode(2);
        TreeNode s2 = new TreeNode(2);

        s0.left = s1;
        s0.right = s2;

        System.out.println(findSecondMinimumValue(s0));
    }

    private static void testCase2() {
        TreeNode s0 = new TreeNode(2);
        TreeNode s1 = new TreeNode(2);
        TreeNode s2 = new TreeNode(5);
        TreeNode s3 = new TreeNode(5);
        TreeNode s4 = new TreeNode(7);

        s2.left = s3;
        s2.right = s4;

        s0.left = s1;
        s0.right = s2;

        System.out.println(findSecondMinimumValue(s0));
    }

    public static int findSecondMinimumValue(TreeNode root) {
        if (root == null || (root.left == null && root.right == null)) {
            return -1;
        }

        int leftMin = root.left.val, rightMin = root.right.val;
        if (leftMin == root.val) {
            leftMin = findSecondMinimumValue(root.left);
        }
        if (rightMin == root.val) {
            rightMin = findSecondMinimumValue(root.right);
        }

        if (leftMin != -1 && rightMin != -1) {
            return Math.min(leftMin, rightMin);
        }
        if (leftMin != -1) {
            return leftMin;
        }
        if (rightMin != -1) {
            return rightMin;
        }

        return -1;
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