package org.ironman.base.playground.leetcode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Solution {

    public static void main(String[] args) {
        Node node5 = new Node(5, new ArrayList<>());
        Node node6 = new Node(6, new ArrayList<>());
        Node node3 = new Node(3, new ArrayList<>());
        node3.children.add(node5);
        node3.children.add(node6);

        Node node2 = new Node(2, new ArrayList<>());
        Node node4 = new Node(4, new ArrayList<>());
        Node node1 = new Node(1, new ArrayList<>());

        node1.children.add(node3);
        node1.children.add(node2);
        node1.children.add(node4);

        System.out.println(levelOrder(node1).toString());
    }

    public static List<List<Integer>> levelOrder(Node root) {
        if (root == null) {
            return new ArrayList<>();
        }

        List<List<Integer>> ret = new ArrayList<>();
        ret.add(new ArrayList<>());

        int curLevel = 0;
        Queue<List<Object>> nodeLevelQ = new LinkedList<>();
        List<Object> lst = new ArrayList<>();
        lst.add(root);
        lst.add(curLevel);
        nodeLevelQ.add(lst);

        while (!nodeLevelQ.isEmpty()) {
            List<Object> tmpLst = nodeLevelQ.poll();
            if (curLevel != (int) tmpLst.get(1)) {
                curLevel++;
                ret.add(new ArrayList<>());
            }

            ret.get(curLevel).add(((Node) tmpLst.get(0)).val);

            for (Node tmpNode : ((Node) tmpLst.get(0)).children) {
                List<Object> nextLst = new ArrayList<>();
                nextLst.add(tmpNode);
                nextLst.add(curLevel + 1);
                nodeLevelQ.add(nextLst);
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

}