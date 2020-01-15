package org.ironman.base.playground.leetcode;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.regex.Pattern;

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

        printLevelTree(t4);
        System.out.println();
        String str = serialize(t4);
        System.out.println(str);
        System.out.println();
        printLevelTree(deserialize(str));
    }

    private static void testCase2() {
        TreeNode t1 = new TreeNode(11);
        TreeNode t2 = new TreeNode(21);
        TreeNode t3 = new TreeNode(31);
        TreeNode t4 = new TreeNode(41);
        TreeNode t5 = new TreeNode(51);
        TreeNode t6 = new TreeNode(61);

        t2.left = t3;
        t2.right = t1;

        t6.left = t5;

        t4.left = t2;
        t4.right = t6;

        printLevelTree(t4);
        System.out.println();
        String str = serialize(t4);
        System.out.println(str);
        System.out.println();
        printLevelTree(deserialize(str));
    }

    private static void testCase3() {
        TreeNode t1 = new TreeNode(1);
        TreeNode t2 = new TreeNode(2);
        TreeNode t3 = new TreeNode(3);
        TreeNode t4 = new TreeNode(4);

        t2.left = t3;
        t2.right = t1;

        t4.left = t2;

        printLevelTree(t4);
        System.out.println();
        String str = serialize(t4);
        System.out.println(str);
        System.out.println();
        printLevelTree(deserialize(str));

    }

    // Encodes a tree to a single string.
    public static String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        preOrderSerializeHelper(root, sb);
        return sb.toString();
    }

    private static Pattern SPACE_PATTERN = Pattern.compile("\\s*[ ]+\\s*");

    // Decodes your encoded data to tree.
    public static TreeNode deserialize(String data) {
        Queue<String> q = new LinkedList<>(Arrays.asList(SPACE_PATTERN.split(data)));
        return deserializeHelper(q);
    }

    private static void preOrderSerializeHelper(TreeNode root, StringBuilder sb) {
        if (root == null) {
            sb.append("#").append(" ");
            return;
        }

        sb.append(root.val).append(" ");
        preOrderSerializeHelper(root.left, sb);
        preOrderSerializeHelper(root.right, sb);
    }

    private static TreeNode deserializeHelper(Queue<String> q) {
        if (q.isEmpty()) {
            return null;
        }

        String topStr = q.poll();
        if (topStr.equals("#")) {
            return null;
        }

        TreeNode root = new TreeNode(Integer.parseInt(topStr));
        root.left = deserializeHelper(q);
        root.right = deserializeHelper(q);
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