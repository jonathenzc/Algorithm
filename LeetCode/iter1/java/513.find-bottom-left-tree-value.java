package org.ironman.base.playground.leetcode;

import java.util.LinkedList;
import java.util.Queue;

public class Solution {

    public static void main(String[] args) {
        testCase1();
        testCase2();
    }

    private static void testCase1() {
        TreeNode s0 = new TreeNode(2);
        TreeNode s1 = new TreeNode(1);
        TreeNode s2 = new TreeNode(3);

        s0.left = s1;
        s0.right = s2;

        System.out.println(findBottomLeftValue(s0));
    }

    private static void testCase2() {
        TreeNode s0 = new TreeNode(1);
        TreeNode s1 = new TreeNode(2);
        TreeNode s2 = new TreeNode(3);
        TreeNode s3 = new TreeNode(4);
        TreeNode s4 = new TreeNode(5);
        TreeNode s5 = new TreeNode(6);
        TreeNode s6 = new TreeNode(7);

        s4.left = s6;
        s2.left = s4;
        s2.right = s5;

        s1.left = s3;

        s0.left = s1;
        s0.right = s2;

        System.out.println(findBottomLeftValue(s0));
    }

    public static int findBottomLeftValue(TreeNode root) {
        Queue<Pair<TreeNode, Integer>> q = new LinkedList<>();
        q.add(new Pair<>(root, 1));

        int ret = -1;
        int curLv = 0;
        while (!q.isEmpty()) {
            Pair<TreeNode, Integer> tmpPair = q.poll();
            if (curLv != tmpPair.getValue()) {
                curLv = tmpPair.getValue();
                ret = tmpPair.getKey().val;
            }

            if (tmpPair.key.left != null) {
                q.add(new Pair<>(tmpPair.key.left, curLv + 1));
            }

            if (tmpPair.key.right != null) {
                q.add(new Pair<>(tmpPair.key.right, curLv + 1));
            }
        }

        return ret;
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