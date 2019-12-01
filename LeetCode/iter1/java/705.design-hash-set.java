package org.ironman.base.playground.leetcode;

public class Solution {

    public static void main(String[] args) {
        MyHashSet hashSet = new MyHashSet();
        hashSet.add(1);
        hashSet.add(2);
        System.out.println(hashSet.contains(1));    // returns true
        System.out.println(hashSet.contains(3));    // returns false (not found)
        hashSet.add(2);
        System.out.println(hashSet.contains(2));    // returns true
        hashSet.remove(2);
        System.out.println(hashSet.contains(2));    // returns false (already removed)
    }

    static class MyHashSet {

        private int[] arr;
        private static final int SIZE = 1000000;
        private static final int USED = 1;
        private static final int NOT_FOUND = 0;
        /**
         * Initialize your data structure here.
         */
        public MyHashSet() {
            arr = new int[SIZE];
            for (int i = 0; i < SIZE; i++) {
                arr[i] = NOT_FOUND;
            }
        }

        public void add(int key) {
            arr[key] = USED;
        }

        public void remove(int key) {
            arr[key] = NOT_FOUND;
        }

        /**
         * Returns true if this set contains the specified element
         */
        public boolean contains(int key) {
            return arr[key] == USED;
        }
    }

}