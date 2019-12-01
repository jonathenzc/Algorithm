package org.ironman.base.playground.leetcode;

public class Solution {

    public static void main(String[] args) {
        TreeNode root = new TreeNode(4);
        TreeNode node1 = new TreeNode(2);
        TreeNode node2 = new TreeNode(1);
        TreeNode node3 = new TreeNode(3);
        TreeNode node4 = new TreeNode(7);

        node1.left = node2;
        node1.right = node3;

        root.left = node1;
        root.right = node4;

        for (int i = 0; i < 11; i++) {
            System.out.println("find " + i);
            System.out.println(searchBST(root, i));
            System.out.println();
        }
    }

    public static TreeNode searchBST(TreeNode root, int val) {
        if(root == null) {
            return null;
        }

        if(val == root.val) {
            return root;
        } else if(val < root.val){
            return searchBST(root.left, val);
        } else {
            return searchBST(root.right, val);
        }
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