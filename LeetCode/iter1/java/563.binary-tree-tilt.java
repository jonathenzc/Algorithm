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
        TreeNode t2 = new TreeNode(3);
        TreeNode t3 = new TreeNode(6);
        TreeNode t4 = new TreeNode(2);
        TreeNode t5 = new TreeNode(4);
        TreeNode t6 = new TreeNode(7);

        t2.left = t4;
        t2.right = t5;

        t3.right = t6;

        t1.left = t2;
        t1.right = t3;

        printLevelTree(t1);
        System.out.println(findTilt(t1));
    }

    private static void testCase2() {
        TreeNode t1 = new TreeNode(5);
        TreeNode t2 = new TreeNode(3);
        TreeNode t3 = new TreeNode(6);
        TreeNode t4 = new TreeNode(2);
        TreeNode t5 = new TreeNode(4);
        TreeNode t6 = new TreeNode(7);

        t2.left = t4;
        t2.right = t5;

        t3.right = t6;

        t1.left = t2;
        t1.right = t3;

        printLevelTree(t1);
        System.out.println(findTilt(t1));
    }

    private static void testCase3() {
        TreeNode t1 = new TreeNode(1);
        TreeNode t2 = new TreeNode(2);
        TreeNode t3 = new TreeNode(3);
        TreeNode t4 = new TreeNode(4);

        t2.left = t3;
        t2.right = t4;

        t1.left = t2;

        printLevelTree(t1);
        System.out.println(findTilt(t1));
    }

    private static int tiltSum = 0;

    public static int findTilt(TreeNode root) {
        tiltSum = 0;
        getChildrenTilt(root);
        return tiltSum;
    }

    private static int getChildrenTilt(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int leftTiltSum = root.left != null ? getChildrenTilt(root.left) + root.left.val : 0;
        int rightTiltSum = root.right != null ? getChildrenTilt(root.right) + root.right.val : 0;

        tiltSum += Math.abs(leftTiltSum - rightTiltSum);
        return leftTiltSum + rightTiltSum;
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