package org.ironman.base.playground.leetcode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.stream.IntStream;

public class Solution {

    public static void main(String[] args) {
        testCase1();
        System.out.println();
        testCase2();
        System.out.println();
        testCase3();
    }

    private static void testCase1() {
        TreeNode s0 = new TreeNode(1);
        TreeNode s1 = new TreeNode(2);

        s0.left = s1;

        print2dLst(printTree(s0));
    }

    private static void testCase2() {
        TreeNode s0 = new TreeNode(1);
        TreeNode s1 = new TreeNode(2);
        TreeNode s2 = new TreeNode(3);
        TreeNode s3 = new TreeNode(4);

        s1.right = s3;
        s0.left = s1;
        s0.right = s2;

        print2dLst(printTree(s0));
    }

    private static void testCase3() {
        TreeNode s0 = new TreeNode(1);
        TreeNode s1 = new TreeNode(2);
        TreeNode s2 = new TreeNode(3);
        TreeNode s3 = new TreeNode(4);
        TreeNode s4 = new TreeNode(5);

        s2.left = s3;
        s1.left = s2;

        s0.left = s1;
        s0.right = s4;

        print2dLst(printTree(s0));
    }

    public static List<List<String>> printTree(TreeNode root) {
        if (root == null) {
            return new ArrayList<>();
        }
        int height = getHeight(root);
        int col = (int) Math.pow(2, height) - 1;
        List<List<String>> ret = new ArrayList<>();
        IntStream.range(0, height).forEach(i -> {
            List<String> tmpL = new ArrayList<>();
            IntStream.range(0, col).forEach(j -> tmpL.add(""));
            ret.add(tmpL);
        });

        Queue<Pair<TreeNode, Integer>> nodeQ = new LinkedList<>();
        Queue<Pair<Integer, Integer>> posQ = new LinkedList<>();
        nodeQ.add(new Pair<>(root, 0));
        posQ.add(new Pair<>(0, col - 1));

        while (!nodeQ.isEmpty()) {
            Pair<TreeNode, Integer> nodePair = nodeQ.poll();
            Pair<Integer, Integer> posPair = posQ.poll();

            int mid = posPair.key + (posPair.value - posPair.key) / 2;
            ret.get(nodePair.value).set(mid, nodePair.key.val + "");

            if (nodePair.key.left != null) {
                nodeQ.add(new Pair<>(nodePair.key.left, nodePair.value + 1));
                posQ.add(new Pair<>(posPair.key, mid - 1));
            }

            if (nodePair.key.right != null) {
                nodeQ.add(new Pair<>(nodePair.key.right, nodePair.value + 1));
                posQ.add(new Pair<>(mid + 1, posPair.value));
            }
        }

        return ret;
    }

    private static int getHeight(TreeNode node) {
        if (node == null) {
            return 0;
        }
        return Math.max(getHeight(node.left), getHeight(node.right)) + 1;
    }

    private static void print2dLst(List<List<String>> lst) {
        for (int i = 0; i < lst.size(); i++) {
            StringBuilder sb = new StringBuilder("[");
            for (int j = 0; j < lst.get(0).size(); j++) {
                sb.append("\"").append(lst.get(i).get(j)).append("\", ");
            }

            String rawStr = sb.toString();
            System.out.println(rawStr.substring(0, rawStr.length() - 2) + "]");
        }
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