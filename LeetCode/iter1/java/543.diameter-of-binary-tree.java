package org.ironman.base.playground.leetcode;

import java.util.ArrayList;
import java.util.List;

public class Solution {

    public static void main(String[] args) {
        System.out.println(diameterOfBinaryTree((testCase1())));
        System.out.println(diameterOfBinaryTree((testCase2())));
        System.out.println(diameterOfBinaryTree((testCase3())));
    }

    private static int diameter = 0;

    public static int diameterOfBinaryTree(TreeNode root) {
        if (root == null) {
            return 0;
        }

        diameter = 0;
        getTreeDepth(root);

        return diameter - 1;
    }

    private static int getTreeDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int LDepth = getTreeDepth(root.left);
        int RDepth = getTreeDepth(root.right);

        diameter = Math.max(diameter, LDepth + RDepth + 1);

        return Math.max(LDepth, RDepth) + 1;
    }

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    //	1
    //2     3
    //4 5
    private static TreeNode testCase1() {
        List<TreeNode> lst = new ArrayList<>();
        for (int i = 0; i <= 5; i++) {
            lst.add(new TreeNode(i));
        }

        lst.get(2).left = lst.get(4);
        lst.get(2).right = lst.get(5);

        lst.get(1).left = lst.get(2);
        lst.get(1).right = lst.get(3);

        return lst.get(1);
    }

    //	1
    //2     3
    //4 5
    //6   7
    //8    9
    //      10
    private static TreeNode testCase2() {
        List<TreeNode> lst = new ArrayList<>();
        for (int i = 0; i <= 10; i++) {
            lst.add(new TreeNode(i));
        }

        lst.get(9).right = lst.get(10);
        lst.get(7).left = lst.get(9);
        lst.get(5).right = lst.get(7);

        lst.get(6).left = lst.get(8);
        lst.get(4).right = lst.get(6);

        lst.get(2).left = lst.get(4);
        lst.get(2).right = lst.get(5);

        lst.get(1).left = lst.get(2);
        lst.get(1).right = lst.get(3);

        return lst.get(1);
    }

    private static TreeNode testCase3() {
        return new TreeNode(1);
    }
}