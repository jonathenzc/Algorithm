package org.ironman.base.playground.leetcode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Solution {

    public static void main(String[] args) {
        TreeNode node3 = new TreeNode(3);
        TreeNode node7 = new TreeNode(7);
        TreeNode node9 = new TreeNode(9);
        TreeNode node15 = new TreeNode(15);
        TreeNode node20 = new TreeNode(20);

        node20.left = node15;
        node20.right = node7;

        node3.left = node9;
        node3.right = node20;

        System.out.println(averageOfLevels(node3));
    }

    public static List<Double> averageOfLevels(TreeNode root) {
        List<Double> ret = new ArrayList<>();
        if (root == null) {
            ret.add(0D);
            return ret;
        }

        Queue<Pair<TreeNode, Integer>> treeNodeQ = new LinkedList<>();
        treeNodeQ.add(new Pair<>(root, 0));

        double levelSum = 0;
        int levelCnt = 0;
        int curLevel = 0;
        while (!treeNodeQ.isEmpty()) {
            Pair<TreeNode, Integer> tmpNode = treeNodeQ.poll();
            if (curLevel != tmpNode.getValue()) {
                ret.add(levelSum / levelCnt);
                levelSum = 0;
                levelCnt = 0;
                curLevel++;
            }

            levelCnt++;
            levelSum += tmpNode.getKey().val;
            if (tmpNode.getKey().left != null) {
                treeNodeQ.add(new Pair<>(tmpNode.getKey().left, curLevel + 1));
            }

            if (tmpNode.getKey().right != null) {
                treeNodeQ.add(new Pair<>(tmpNode.getKey().right, curLevel + 1));
            }
        }

        ret.add(levelSum / levelCnt);
        return ret;
    }

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    public static class Pair<K, V> {
        K key;
        V value;

        public V getValue() {
            return value;
        }

        public K getKey() {
            return key;
        }

        Pair(K _key, V _value) {
            key = _key;
            value = _value;
        }
    }
}