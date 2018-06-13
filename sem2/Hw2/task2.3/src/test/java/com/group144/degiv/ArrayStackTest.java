package com.group144.degiv;

import com.sun.javafx.image.IntPixelGetter;
import org.junit.Test;

import static org.junit.Assert.*;

public class ArrayStackTest {
    @Test
    public void pushAndPop() {
        Stack<Integer> numbers = new ArrayStack<>();
        for (Integer i = 0; i < 30; ++i)
            numbers.push(i);
        for (Integer i = 29; i >= 0; --i)
            assertEquals(i, numbers.pop());
    }

    @Test
    public void isEmpty() {
        Stack<Integer> numbers = new ArrayStack<>();

        for (Integer i = 0; i < 30; ++i)
            numbers.push(i);
        assertEquals(false, numbers.isEmpty());

        for (Integer i = 29; i >= 0; --i)
            numbers.pop();
        assertEquals(true, numbers.isEmpty());
    }
}