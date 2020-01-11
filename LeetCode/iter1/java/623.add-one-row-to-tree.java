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
        testCase3();
    }

    private static void testCase1() {
        TreeNode t1 = new TreeNode(1);
        TreeNode t2 = new TreeNode(2);
        TreeNode t3 = new TreeNode(3);
        TreeNode t4 = new TreeNode(4);
        TreeNode t5 = new TreeNode(5);
        TreeNode t6 = new TreeNode(6);

        t2.left = t3;
        t2.right = t1;

        t6.left = t5;

        t4.left = t2;
        t4.right = t6;

        printLevelTree(addOneRow(t4, 100, 1));
    }

    private static void testCase2() {
        TreeNode t1 = new TreeNode(1);
        TreeNode t2 = new TreeNode(2);
        TreeNode t3 = new TreeNode(3);
        TreeNode t4 = new TreeNode(4);
        TreeNode t5 = new TreeNode(5);
        TreeNode t6 = new TreeNode(6);

        t2.left = t3;
        t2.right = t1;

        t6.left = t5;

        t4.left = t2;
        t4.right = t6;

        printLevelTree(addOneRow(t4, 1, 2));
    }

    private static void testCase3() {
        TreeNode t1 = new TreeNode(1);
        TreeNode t2 = new TreeNode(2);
        TreeNode t3 = new TreeNode(3);
        TreeNode t4 = new TreeNode(4);

        t2.left = t3;
        t2.right = t1;

        t4.left = t2;

        printLevelTree(addOneRow(t4, 1, 3));
    }

    public static TreeNode addOneRow(TreeNode root, int v, int d) {
        if (d == 1) {
            TreeNode tmp = new TreeNode(v);
            tmp.left = root;
            root = tmp;
            return root;
        }

        Queue<Pair<TreeNode, Integer>> treeNodeQ = new LinkedList<>();
        treeNodeQ.add(new Pair<>(root, 1));

        //find parent level
        List<TreeNode> parentLayer = new ArrayList<>();
        while (!treeNodeQ.isEmpty()) {
            Pair<TreeNode, Integer> tmpPair = treeNodeQ.poll();
            if (tmpPair.getValue() == d - 1) {
                parentLayer.add(tmpPair.key);
            } else {
                if (tmpPair.key.left != null) {
                    treeNodeQ.add(new Pair<>(tmpPair.key.left, tmpPair.value + 1));
                }

                if (tmpPair.key.right != null) {
                    treeNodeQ.add(new Pair<>(tmpPair.key.right, tmpPair.value + 1));
                }
            }
        }

        //add one row to parent layer
        for (TreeNode parentNode : parentLayer) {
            TreeNode leftTmpNode = new TreeNode(v);
            leftTmpNode.left = parentNode.left;
            TreeNode rightTmpNode = new TreeNode(v);
            rightTmpNode.right = parentNode.right;

            parentNode.left = leftTmpNode;
            parentNode.right = rightTmpNode;
        }

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