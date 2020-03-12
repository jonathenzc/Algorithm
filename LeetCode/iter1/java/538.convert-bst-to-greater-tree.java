package org.ironman.base.playground.leetcode;

import java.util.LinkedList;
import java.util.Queue;

public class Solution {

    public static void main(String[] args) {
        testCase1();
        System.out.println();
        testCase2();
        System.out.println();
        testCase3();
        System.out.println();
    }

    private static void testCase1() {
        TreeNode t1 = new TreeNode(5);
        TreeNode t2 = new TreeNode(2);
        TreeNode t3 = new TreeNode(13);

        t1.left = t2;
        t1.right = t3;

        printLevelTree(t1);
        System.out.println();
        printLevelTree(convertBST(t1));
        System.out.println();
    }

    private static void testCase2() {
        TreeNode t1 = new TreeNode(1);
        TreeNode t2 = new TreeNode(2);
        TreeNode t3 = new TreeNode(3);
        TreeNode t4 = new TreeNode(4);
        TreeNode t5 = new TreeNode(5);
        TreeNode t6 = new TreeNode(6);
        TreeNode t7 = new TreeNode(7);
        TreeNode t8 = new TreeNode(8);

        t6.left = t5;

        t7.left = t6;
        t7.right = t8;

        t2.left = t1;
        t2.right = t3;

        t4.left = t2;
        t4.right = t7;

        printLevelTree(t4);
        System.out.println();
        printLevelTree(convertBST(t4));
        System.out.println();
    }

    private static void testCase3() {
        TreeNode t1 = new TreeNode(1);
        TreeNode t2 = new TreeNode(2);
        TreeNode t3 = new TreeNode(3);
        TreeNode t4 = new TreeNode(4);

        t4.left = t3;
        t3.left = t2;
        t2.left = t1;

        printLevelTree(t4);
        System.out.println();
        printLevelTree(convertBST(t4));
        System.out.println();
    }

    public static TreeNode convertBST(TreeNode root) {
        convertChildBST(root, 0);
        return root;
    }

    public static int convertChildBST(TreeNode root, int greaterSum) {
        if (root == null) {
            return 0;
        }

        int originVal = root.val;
        int rightSum = convertChildBST(root.right, greaterSum);
        int leftSum = convertChildBST(root.left, originVal + greaterSum + rightSum);

        root.val += greaterSum + rightSum;

        return originVal + leftSum + rightSum;
    }

    private static void printLevelTree(TreeNode root) {
        Queue<Pair<TreeNode, Integer>> q = new LinkedList<>();
        q.add(new Pair<>(root, 1));
        int curLv = 1;
        while (!q.isEmpty()) {
            Pair<TreeNode, Integer> tmpPair = q.poll();
            if (tmpPair.getValue() != curLv) {
                curLv = tmpPair.getValue();
                System.out.println();
            }

            System.out.print(tmpPair.getKey().val + " ");
            if (tmpPair.getKey().left != null) {
                q.add(new Pair<>(tmpPair.getKey().left, tmpPair.getValue() + 1));
            }

            if (tmpPair.getKey().right != null) {
                q.add(new Pair<>(tmpPair.getKey().right, tmpPair.getValue() + 1));
            }
        }
        System.out.println();
    }

    static public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    static public class Pair<K, V> {
        private K key;
        private V value;

        Pair(K _key, V _value) {
            key = _key;
            value = _value;
        }

        public K getKey() {
            return key;
        }

        public V getValue() {
            return value;
        }
    }
}