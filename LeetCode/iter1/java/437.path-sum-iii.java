package org.ironman.base.playground.leetcode;

public class Solution {

    public static void main(String[] args) {
        TreeNode node1 = new TreeNode(10);
        TreeNode node2 = new TreeNode(5);
        TreeNode node3 = new TreeNode(-3);
        TreeNode node4 = new TreeNode(3);
        TreeNode node5 = new TreeNode(2);
        TreeNode node6 = new TreeNode(11);
        TreeNode node7 = new TreeNode(3);
        TreeNode node8 = new TreeNode(-2);
        TreeNode node9 = new TreeNode(1);

        node4.left = node7;
        node4.right = node8;

        node5.right = node9;
        node2.left = node4;
        node2.right = node5;

        node3.right = node6;
        node1.left = node2;
        node1.right = node3;

        System.out.println(pathSum(node1, 8));
    }

    public static int pathSum(TreeNode root, int sum) {
        if (root == null) {
            return 0;
        }

        return childrenPathSumFromRoot(root, sum) + pathSum(root.left, sum) + pathSum(root.right, sum);
    }

    private static int childrenPathSumFromRoot(TreeNode root, int sum) {
        if (root == null) {
            return 0;
        }

        return (root.val == sum ? 1 : 0) +
                childrenPathSumFromRoot(root.left, sum - root.val) +
                childrenPathSumFromRoot(root.right, sum - root.val);
    }


    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }
}