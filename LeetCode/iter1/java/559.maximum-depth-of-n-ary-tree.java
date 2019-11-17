package org.ironman.base.playground.leetcode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Solution {

    public static void main(String[] args) {
        List<Node> l1 = new ArrayList<>();
        List<Node> l2 = new ArrayList<>();
        List<Node> l3 = new ArrayList<>();
        List<Node> l4 = new ArrayList<>();
        List<Node> l5 = new ArrayList<>();
        List<Node> l6 = new ArrayList<>();

        Node node1 = new Node(1, l1);
        Node node2 = new Node(2, l2);
        Node node3 = new Node(3, l3);
        Node node4 = new Node(4, l4);
        Node node5 = new Node(5, l5);
        Node node6 = new Node(6, l6);

        node3.children.add(node5);
        node3.children.add(node6);

        node1.children.add(node3);
        node1.children.add(node2);
        node1.children.add(node4);

        System.out.println(maxDepth(node1));
    }

    //recursion
    public static int maxDepthRecursion(Node root) {
        if (root == null) {
            return 0;
        }

        int ret = 1;
        for (Node node : root.children) {
            ret = Math.max(ret, maxDepthRecursion(node) + 1);
        }

        return ret;
    }

    //iteration
    public static int maxDepth(Node root) {
        if (root == null) {
            return 0;
        }

        Queue<Pair<Node, Integer>> q = new LinkedList<>();
        q.add(new Pair<>(root, 1));
        int ret = 0;
        while (!q.isEmpty()) {
            Pair<Node, Integer> tmpPair = q.poll();
            ret = Math.max(ret, tmpPair.value);

            for (Node node : tmpPair.key.children) {
                q.add(new Pair<>(node, tmpPair.value + 1));
            }
        }

        return ret;
    }

    static class Node {
        public int val;
        public List<Node> children;

        public Node() {
        }

        public Node(int _val, List<Node> _children) {
            val = _val;
            children = _children;
        }
    }

    static class Pair<K, V> {
        public K key;
        public V value;

        public Pair() {
        }

        public Pair(K _key, V _value) {
            key = _key;
            value = _value;
        }
    }
}