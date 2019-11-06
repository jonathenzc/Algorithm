package org.ironman.base.playground.leetcode;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class Solution {

    public static void main(String[] args) {
        Node node5 = new Node(5, null);
        Node node6 = new Node(6, null);
        List<Node> lst3 = new ArrayList<>();
        lst3.add(node5);
        lst3.add(node6);
        Node node3 = new Node(3, lst3);

        Node node2 = new Node(2, null);
        Node node4 = new Node(4, null);
        List<Node> lst1 = new ArrayList<>();
        lst1.add(node3);
        lst1.add(node2);
        lst1.add(node4);

        Node node1 = new Node(1, lst1);

        System.out.println(preorder(node1));
    }

    public static List<Integer> preorder(Node root) {
        if (root == null) {
            return new ArrayList<>();
        }

        List<Integer> ret = new ArrayList<>();
        Stack<Node> stack = new Stack<>();
        stack.add(root);

        while (!stack.isEmpty()) {
            Node tmp = stack.pop();
            if (tmp == null) {
                continue;
            }
            ret.add(tmp.val);

            if (tmp.children == null) {
                continue;
            }
            for (int i = tmp.children.size() - 1; i >= 0; i--) {
                stack.push(tmp.children.get(i));
            }
        }

        return ret;
    }

    //recursion
//    public static List<Integer> preorder(Node root) {
//        if (root == null) {
//            return new ArrayList<>();
//        }
//
//        List<Integer> ret = new ArrayList<>();
//        ret.add(root.val);
//        if (root.children == null) {
//            return ret;
//        }
//        for (Node node : root.children) {
//            List<Integer> tmpLst = preorder(node);
//            for (int num : tmpLst) {
//                ret.add(num);
//            }
//        }
//
//        return ret;
//    }

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