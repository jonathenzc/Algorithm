package org.ironman.base.playground.leetcode;

import java.util.LinkedList;
import java.util.Queue;

public class Solution {

    public static void main(String[] args) {
        testCase1();
        System.out.println();
        testCase2();
        System.out.println();
    }

    private static void testCase1() {
        TreeNode node1 = new TreeNode(5);
        TreeNode node2 = new TreeNode(4);
        TreeNode node3 = new TreeNode(5);
        TreeNode node4 = new TreeNode(1);
        TreeNode node5 = new TreeNode(1);
        TreeNode node6 = new TreeNode(5);

        node2.left = node4;
        node2.right = node5;

        node3.right = node6;

        node1.left = node2;
        node1.right = node3;

        printLevelTree(node1);
        System.out.println();

        System.out.println(longestUnivaluePath(node1));
    }

    private static void testCase2() {
        TreeNode node1 = new TreeNode(1);
        TreeNode node2 = new TreeNode(4);
        TreeNode node3 = new TreeNode(5);
        TreeNode node4 = new TreeNode(4);
        TreeNode node5 = new TreeNode(4);
        TreeNode node6 = new TreeNode(5);

        node2.left = node4;
        node2.right = node5;

        node3.right = node6;

        node1.left = node2;
        node1.right = node3;

        printLevelTree(node1);
        System.out.println();

        System.out.println(longestUnivaluePath(node1));
    }

    private static int longestPath;

    public static int longestUnivaluePath(TreeNode root) {
        longestPath = 0;
        getChildrenLongestPath(root);
        return longestPath;
    }

    private static int getChildrenLongestPath(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int leftVal = getChildrenLongestPath(root.left);
        int rightVal = getChildrenLongestPath(root.right);

        leftVal = root.left != null && root.left.val == root.val ? leftVal + 1 : 0;
        rightVal = root.right != null && root.right.val == root.val ? rightVal + 1 : 0;
        longestPath = Math.max(longestPath, leftVal + rightVal);
        return Math.max(leftVal, rightVal);
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