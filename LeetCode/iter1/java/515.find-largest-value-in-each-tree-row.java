package org.ironman.base.playground.leetcode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Solution {

    public static void main(String[] args) {
        testCase1();
        System.out.println();
        testCase2();
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
        System.out.println();
        System.out.println(largestValues(t1));
    }

    private static void testCase2() {
        TreeNode t1 = new TreeNode(5);
        TreeNode t2 = new TreeNode(9);
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
        System.out.println();
        System.out.println(largestValues(t1));
    }

    public static List<Integer> largestValues(TreeNode root) {
        List<Integer> ret = new ArrayList<>();
        if (root == null) {
            return ret;
        }

        Queue<Pair<TreeNode, Integer>> q = new LinkedList<>();
        q.add(new Pair<>(root, 1));
        int curLv = 1, lvMaxVal = Integer.MIN_VALUE;
        while (!q.isEmpty()) {
            Pair<TreeNode, Integer> treePair = q.poll();
            if (treePair.getValue() != curLv) {
                ret.add(lvMaxVal);
                curLv = treePair.getValue();
                lvMaxVal = treePair.getKey().val;
            } else {
                lvMaxVal = Math.max(lvMaxVal, treePair.getKey().val);
            }

            if (treePair.getKey().left != null) {
                q.add(new Pair<>(treePair.getKey().left, treePair.getValue() + 1));
            }

            if (treePair.getKey().right != null) {
                q.add(new Pair<>(treePair.getKey().right, treePair.getValue() + 1));
            }
        }

        ret.add(lvMaxVal);

        return ret;
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