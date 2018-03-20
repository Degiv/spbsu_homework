package com.group144.degiv;

import org.junit.Test;

import static org.junit.Assert.*;

public class LinkedPriorityQueueTest {

    @Test
    public void enqueueAndDequeue() {
        PriorityQueue<Character> numbers = new LinkedPriorityQueue<>();
        numbers.enqueue('d', 5);
        numbers.enqueue('a', 10);
        numbers.enqueue('b', 7);
        numbers.enqueue('c', 6);
        numbers.enqueue('e', 2);
        Character expected = 'a';
        for (int i = 0; i < 5; ++i) {
            assertEquals(expected, numbers.dequeue());
            expected ++;
        }
    }
}