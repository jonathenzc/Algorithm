package org.ironman.leetcode;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

public class Solution {

    public static String tree2str(TreeNode t) {
        if (t == null) {
            return "";
        }

        StringBuilder ret = new StringBuilder("" + t.val);
        if (t.left == null && t.right == null) {
            return ret.toString();
        }

        ret.append("(").append(tree2str(t.left)).append(")");

        if (t.right != null) {
            ret.append("(").append(tree2str(t.right)).append(")");
        }

        return ret.toString();
    }

    public static void main(String[] args) {
        //test case1
        TreeNode eg1Node1 = new TreeNode(1);
        TreeNode eg1Node2 = new TreeNode(2);
        TreeNode eg1Node3 = new TreeNode(3);
        TreeNode eg1Node4 = new TreeNode(4);

        eg1Node2.left = eg1Node4;
        eg1Node1.left = eg1Node2;
        eg1Node1.right = eg1Node3;

        //test case2
        TreeNode eg2Node1 = new TreeNode(1);
        TreeNode eg2Node2 = new TreeNode(2);
        TreeNode eg2Node3 = new TreeNode(3);
        TreeNode eg2Node4 = new TreeNode(4);

        eg2Node2.right = eg2Node4;
        eg2Node1.left = eg2Node2;
        eg2Node1.right = eg2Node3;

        System.out.println(tree2str(eg1Node1));
        System.out.println(tree2str(eg2Node1));
    }
}