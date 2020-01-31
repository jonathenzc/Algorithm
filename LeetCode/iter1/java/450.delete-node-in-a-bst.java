package org.ironman.base.playground.leetcode;

import java.util.LinkedList;
import java.util.Queue;

public class Solution {

    public static void main(String[] args) {
        testCase1();
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
        printLevelTree(deleteNode(t1, 3));
    }

    public static TreeNode deleteNode(TreeNode root, int key) {
        //step1: find target node
        TreeNode parentNode = null, originRoot = root;
        while (root != null && root.val != key) {
            parentNode = root;
            if (root.val < key) {
                root = root.right;
            } else if (root.val > key) {
                root = root.left;
            }
        }

        //step2: delete the target node
        if (parentNode == null) {
            return deleteTargetNode(root);
        }

        if (parentNode.left == root) {
            parentNode.left = deleteTargetNode(root);
        } else if (parentNode.right == root) {
            parentNode.right = deleteTargetNode(root);
        }

        return originRoot;
    }

    private static TreeNode deleteTargetNode(TreeNode root) {
        if (root == null) {
            return null;
        }

        //一边的子树为空则返回另一边子树
        if (root.left == null) {
            return root.right;
        }
        if (root.right == null) {
            return root.left;
        }

        //两边子树均不为空，找到右子树的最左边作为根节点
        TreeNode parentNode = root, rightLeftestNode = root.right;
        while (rightLeftestNode.left != null) {
            parentNode = rightLeftestNode;
            rightLeftestNode = rightLeftestNode.left;
        }

        rightLeftestNode.left = root.left;
        if (parentNode != root) {
            parentNode.left = rightLeftestNode.right;
            rightLeftestNode.right = root.right;
        }

        return rightLeftestNode;
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