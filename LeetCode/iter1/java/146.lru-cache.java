package org.ironman.base.playground.leetcode;

import java.util.HashMap;
import java.util.Map;

public class LRUCache {
    private int capacity;
    private DLinkNode head;
    private DLinkNode tail;
    private Map<Integer, DLinkNode> key2Node;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        key2Node = new HashMap<>();
        head = new DLinkNode(0, 0);
        tail = new DLinkNode(0, 0);

        head.next = tail;
        head.pre = null;
        tail.next = null;
        tail.pre = head;
    }

    public int get(int key) {
        DLinkNode tmp = key2Node.get(key);
        if (tmp == null) {
            return -1;
        }

        int val = tmp.val;
        removeNode(key);
        insertNode(key, val);
        return val;
    }

    public void put(int _key, int _value) {
        if (key2Node.containsKey(_key)) {
            removeNode(_key);
        }

        if (key2Node.size() == capacity) {
            removeNode(head.next.key);
        }

        insertNode(_key, _value);
    }

    private void insertNode(int _key, int _value) {
        DLinkNode tmpNode = new DLinkNode(_key, _value);
        key2Node.put(_key, tmpNode);

        tail.pre.next = tmpNode;
        tmpNode.next = tail;
        tmpNode.pre = tail.pre;
        tail.pre = tmpNode;
    }

    private void removeNode(int _key) {
        DLinkNode tmpNode = key2Node.get(_key);
        key2Node.remove(_key);

        tmpNode.pre.next = tmpNode.next;
        tmpNode.next.pre = tmpNode.pre;
    }

    static class DLinkNode {
        DLinkNode(int _key, int _val) {
            key = _key;
            val = _val;
            next = null;
            pre = null;
        }

        DLinkNode next;
        DLinkNode pre;
        int key;
        int val;
    }

    private static void testCase1() {
        LRUCache cache = new LRUCache(2 /* capacity */);

        cache.put(1, 1);
        cache.put(2, 2);
        System.out.println(cache.get(1));        // returns 1
        cache.put(3, 3);           // evicts key 2
        System.out.println(cache.get(2));       // returns -1 (not found)
        cache.put(4, 4);    // evicts key 1
        System.out.println(cache.get(1));       // returns -1 (not found)
        System.out.println(cache.get(3));       // returns 3
        System.out.println(cache.get(4));       // returns 4
    }

    private static void testCase2() {
        LRUCache cache = new LRUCache(1);
        cache.put(2, 1);
        System.out.println(cache.get(2));        // returns 1
        cache.put(3, 2);
        System.out.println(cache.get(2));        // returns -1
        System.out.println(cache.get(3));        // returns 2
    }

    public static void main(String[] args) {
        testCase1();
        System.out.println();
        testCase2();
        System.out.println();
    }
}
