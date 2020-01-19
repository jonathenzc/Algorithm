package org.ironman.base.playground.leetcode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
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
        System.out.println();
        List<TreeNode> lst = findDuplicateSubtrees(t1);
        for (TreeNode root : lst) {
            printLevelTree(root);
            System.out.println();
        }
    }

    public static List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        Map<String, List<TreeNode>> serializeStr2Lst = new HashMap<>();
        serializeTreeNode(root, serializeStr2Lst);

        List<TreeNode> ret = new ArrayList<>();
        serializeStr2Lst.forEach((key, lst) -> {
            if (lst.size() > 1) {
                ret.add(lst.get(0));
            }
        });
        return ret;
    }

    private static String serializeTreeNode(TreeNode root, Map<String, List<TreeNode>> str2lst) {
        if (root == null) {
            return "#";
        }

        String serializeStr = root.val + serializeTreeNode(root.left, str2lst) + serializeTreeNode(root.right, str2lst);
        List<TreeNode> lst = str2lst.getOrDefault(serializeStr, new ArrayList<>());
        lst.add(root);
        str2lst.put(serializeStr, lst);
        return serializeStr;
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