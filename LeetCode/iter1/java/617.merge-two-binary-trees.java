package org.ironman.base.playground.leetcode;

public class Solution {

    public static void main(String[] args) {
        TreeNode t1 = new TreeNode(1);
        TreeNode t1l = new TreeNode(3);
        TreeNode t1r = new TreeNode(2);
        TreeNode t1ll = new TreeNode(5);

        t1.left = t1l;
        t1.right = t1r;
        t1l.left = t1ll;

        TreeNode t2 = new TreeNode(2);
        TreeNode t2l = new TreeNode(1);
        TreeNode t2r = new TreeNode(3);
        TreeNode t2lr = new TreeNode(4);
        TreeNode t2rr = new TreeNode(7);

        t2.left = t2l;
        t2.right = t2r;
        t2l.right = t2lr;
        t2r.right = t2rr;

        preOrder(mergeTrees(t1, t2));
    }

    public static TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        if (t1 == null && t2 == null) {
            return null;
        }

        TreeNode treeNode = new TreeNode((t1 != null ? t1.val : 0) + (t2 != null ? t2.val : 0));
        treeNode.left = mergeTrees(t1 != null ? t1.left : null, t2 != null ? t2.left : null);
        treeNode.right = mergeTrees(t1 != null ? t1.right : null, t2 != null ? t2.right : null);
        return treeNode;
    }

    private static void preOrder(TreeNode treeNode) {
        if(treeNode == null) {
            return;
        }
        System.out.println(treeNode.val);
        preOrder(treeNode.left);
        preOrder(treeNode.right);
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