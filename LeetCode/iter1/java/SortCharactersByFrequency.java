package org.ironman;


import javafx.util.Pair;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;

public class Main {

    //solution1: shell sort
    public static List<Integer> topKFrequent1(int[] nums, int k) {
        Map<Integer, Integer> frequency = new HashMap<>();
        Arrays.stream(nums).forEach(num -> {
            Integer cnt = frequency.get(num);
            if (cnt == null) {
                frequency.put(num, 1);
            } else {
                frequency.put(num, cnt + 1);
            }
        });

        List<Integer>[] shellLst = new List[nums.length + 1];
        frequency.entrySet().forEach(entry -> {
            if (isEmpty(shellLst[entry.getValue()])) {
                shellLst[entry.getValue()] = new ArrayList<>();
            }
            shellLst[entry.getValue()].add(entry.getKey());
        });

        List<Integer> ret = new ArrayList<>();
        for (int i = 0; i < shellLst.length; i++) {
            List<Integer> bucketLst = shellLst[shellLst.length - 1 - i];
            if (!isEmpty(bucketLst)) {
                int bucketIdx = 0;
                while (bucketIdx < bucketLst.size() && ret.size() < k) {
                    ret.add(bucketLst.get(bucketIdx++));
                }
            }
        }

        return ret;
    }

    private static boolean isEmpty(List<?> lst) {
        return lst == null || lst.size() == 0;
    }

    //solution2: heap
    public static List<Integer> topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> frequency = new HashMap<>();
        Arrays.stream(nums).forEach(num -> {
            Integer cnt = frequency.get(num);
            if (cnt == null) {
                frequency.put(num, 1);
            } else {
                frequency.put(num, cnt + 1);
            }
        });

        //n-k大小的最大堆 <num, cnt>
        PriorityQueue<Pair<Integer, Integer>> priorityQueue = new PriorityQueue<>(frequency.size() + 1 - k, (o1, o2) -> o2.getValue() - o1.getValue());
        List<Integer> ret = new ArrayList<>();
        frequency.entrySet().forEach(entry -> {
            if (priorityQueue.size() < frequency.size() - k) {
                priorityQueue.add(new Pair<>(entry.getKey(), entry.getValue()));
            } else {
                priorityQueue.add(new Pair<>(entry.getKey(), entry.getValue()));
                ret.add(priorityQueue.peek().getKey());
                priorityQueue.poll();
            }
        });

        return ret;
    }

    public static void main(String[] args) {
        int[] nums1 = new int[6];
        nums1[0] = 5;
        nums1[1] = 5;
        nums1[2] = 5;
        nums1[3] = 15;
        nums1[4] = 15;
        nums1[5] = 10;

        System.out.println(topKFrequent(nums1, 2).toString());
        System.out.println(topKFrequent(nums1, 3).toString());

        int[] nums2 = new int[2];
        nums2[0] = -1;
        nums2[1] = -1;

        System.out.println(topKFrequent(nums2, 1).toString());
    }
}
