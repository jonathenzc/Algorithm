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
        int[] nums = new int[]{3, 2, 1, 6, 0, 5};

        printLevelTree(constructMaximumBinaryTree(nums));
        System.out.println();
    }

    private static void testCase2() {
        int[] nums = new int[]{1, 2, 3, 4, 5, 6, 7, 8};

        printLevelTree(constructMaximumBinaryTree(nums));
        System.out.println();
    }

    private static void testCase3() {
        int[] nums = new int[]{4, 3, 2, 1};

        printLevelTree(constructMaximumBinaryTree(nums));
        System.out.println();
    }

    public static TreeNode constructMaximumBinaryTree(int[] nums) {
        if (nums.length == 0) {
            return null;
        }

        if (nums.length == 1) {
            return new TreeNode(nums[0]);
        }

        return constructHelper(nums, 0, nums.length);
    }

    private static TreeNode constructHelper(int[] nums, int start, int end) {
        if (start >= end) {
            return null;
        }

        int maxVal = Integer.MIN_VALUE, maxIdx = -1;
        for (int i = start; i < end; i++) {
            if (maxVal < nums[i]) {
                maxVal = nums[i];
                maxIdx = i;
            }
        }

        TreeNode root = new TreeNode(maxVal);
        root.left = constructHelper(nums, start, maxIdx);
        root.right = constructHelper(nums, maxIdx + 1, end);

        return root;
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