package org.ironman.base.playground.leetcode;

import java.util.LinkedList;
import java.util.Queue;

public class Solution {

    public static void main(String[] args) {
        testCase1();
        System.out.println();
    }

    private static void testCase1() {
        TreeNode t1 = new TreeNode(4);
        TreeNode t2 = new TreeNode(2);
        TreeNode t3 = new TreeNode(1);
        TreeNode t4 = new TreeNode(3);
        TreeNode t5 = new TreeNode(6);

        t2.left = t3;
        t2.right = t4;

        t1.left = t2;
        t1.right = t5;

        System.out.println(minDiffInBST(t1));
    }

    private static int minDiff = Integer.MAX_VALUE;
    private static int preNum = Integer.MIN_VALUE;

    public static int minDiffInBST(TreeNode root) {
        minDiff = Integer.MAX_VALUE;
        preNum = Integer.MIN_VALUE;
        inorderHelper(root);
        return minDiff;
    }

    private static void inorderHelper(TreeNode root) {
        if (root.left != null) {
            inorderHelper(root.left);
        }

        if (preNum != Integer.MIN_VALUE) {
            minDiff = Math.min(minDiff, root.val - preNum);
        }

        preNum = root.val;
        if (root.right != null) {
            inorderHelper(root.right);
        }
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