package org.ironman.base.playground.leetcode;

import java.util.concurrent.CountDownLatch;

class Foo {

    private static CountDownLatch firstLatch = new CountDownLatch(1);
    private static CountDownLatch secondLatch = new CountDownLatch(1);

    public Foo() {

    }

    public static void first(Runnable printFirst) throws InterruptedException {

        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        firstLatch.countDown();
    }

    public static void second(Runnable printSecond) throws InterruptedException {
        firstLatch.await();
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        secondLatch.countDown();
    }

    public static void third(Runnable printThird) throws InterruptedException {
        firstLatch.await();
        secondLatch.await();

        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }

    public static void main(String[] args) throws InterruptedException {
        PrintRunnable run1 = new PrintRunnable("first");
        PrintRunnable run2 = new PrintRunnable("second");
        PrintRunnable run3 = new PrintRunnable("third");

        first(run1);
        second(run2);
        third(run3);
    }

    static class PrintRunnable implements Runnable {
        String name;

        PrintRunnable(String _name) {
            this.name = _name;
        }

        @Override
        public void run() {
            System.out.println(name);
        }
    }
}
