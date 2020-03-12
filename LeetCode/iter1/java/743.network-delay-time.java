package org.ironman.base.playground.leetcode;

import java.util.LinkedList;
import java.util.Queue;

public class Solution {

    public static void main(String[] args) {
        testCase1();
        System.out.println();
    }

    private static void testCase1() {
        int[] edge1 = new int[]{2, 1, 1};
        int[] edge2 = new int[]{2, 3, 1};
        int[] edge3 = new int[]{3, 4, 1};
        int[][] edges = new int[][]{edge1, edge2, edge3};

        System.out.println(networkDelayTime(edges, 4, 2));
    }

    public static int networkDelayTime(int[][] times, int N, int K) {
        int[] dist = new int[N + 1];
        for (int i = 0; i < N + 1; i++) {
            dist[i] = Integer.MAX_VALUE;
        }
        //distance of source node is 0
        dist[K] = 0;
        //traverse N node
        for (int i = 0; i < N; i++) {
            for (int[] edge : times) {
                int s = edge[0], t = edge[1], cost = edge[2];
                if (dist[s] != Integer.MAX_VALUE && dist[t] > dist[s] + cost) {
                    dist[t] = dist[s] + cost;
                }
            }
        }

        int maxCost = Integer.MIN_VALUE;
        for (int i = 1; i <= N; i++) {
            maxCost = Math.max(maxCost, dist[i]);
        }
        return maxCost == Integer.MAX_VALUE ? -1 : maxCost;
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