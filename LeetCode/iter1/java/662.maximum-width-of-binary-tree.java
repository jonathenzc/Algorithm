package org.ironman.base.playground.leetcode;

import java.util.LinkedList;
import java.util.Queue;

public class Solution {

    public static void main(String[] args) {
        testCase1();
        System.out.println();
    }

    private static void testCase1() {
        TreeNode t1 = new TreeNode(1);
        TreeNode t2 = new TreeNode(2);
        TreeNode t3 = new TreeNode(3);
        TreeNode t4 = new TreeNode(4);
        TreeNode t5 = new TreeNode(2);
        TreeNode t6 = new TreeNode(4);
        TreeNode t7 = new TreeNode(4);

        t5.left = t6;

        t3.left = t5;
        t3.right = t7;

        t2.left = t4;

        t1.left = t2;
        t1.right = t3;

        printLevelTree(t1);
        System.out.println(widthOfBinaryTree(t1));
    }

    public static int widthOfBinaryTree(TreeNode root) {
        if (root == null) {
            return 0;
        }

        //substitute val by idx cause val is useless in this problem
        LinkedList<TreeNode> q = new LinkedList<>();
        root.val = 1;
        q.add(root);

        int ret = 0;
        while (!q.isEmpty()) {
            int thisLvWidth = q.size();
            if (thisLvWidth == 1) {
                q.peek().val = 1;
                q.add(q.peek());
                q.poll();
            }
            ret = Math.max(ret, q.getLast().val - q.getFirst().val + 1);
            for (int i = 0; i < thisLvWidth; i++) {
                TreeNode treeNode = q.poll();
                if (treeNode.left != null) {
                    treeNode.left.val = 2 * treeNode.val;
                    q.add(treeNode.left);
                }

                if (treeNode.right != null) {
                    treeNode.right.val = 2 * treeNode.val + 1;
                    q.add(treeNode.right);
                }
            }
        }
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