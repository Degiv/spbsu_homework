package com.group144.degiv;

import org.junit.Test;

import static org.junit.Assert.*;

public class LinkedPriorityQueueTest {

    @Test
    public void enqueueAndDequeue() {
        PriorityQueue<Character> characters = new LinkedPriorityQueue<>();
        characters.enqueue('d', 5);
        characters.enqueue('a', 10);
        characters.enqueue('b', 7);
        characters.enqueue('c', 6);
        characters.enqueue('e', 2);
        Character expected = 'a';
        for (int i = 0; i < 5; ++i) {
            assertEquals(expected, characters.dequeue());
            expected ++;
        }
    }
}