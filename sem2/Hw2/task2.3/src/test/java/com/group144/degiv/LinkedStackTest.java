package com.group144.degiv;

import org.junit.Test;
import static org.junit.Assert.*;

public class LinkedStackTest {

    @Test
    public void addAndPop() {
        Stack<Integer> numbers = new LinkedStack<>();
        for (int i = 0; i < 10; i++) {
            numbers.push(i);
        }

        for (Integer i = 9; i >= 0; i--) {
            assertEquals(i, numbers.pop());
        }
    }

    @Test
    public void isEmpty() {
        Stack<Integer> numbers = new LinkedStack<>();
        numbers.push(7);
        assertEquals(false, numbers.isEmpty());

        numbers.pop();
        assertEquals(true, numbers.isEmpty());
    }
}