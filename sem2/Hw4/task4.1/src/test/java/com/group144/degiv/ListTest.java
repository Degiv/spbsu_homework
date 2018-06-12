package com.group144.degiv;

import org.junit.Test;

import static org.junit.Assert.*;

public class ListTest {

    @Test
    public void isEmpty() throws ValueAlreadyContainedException, IncorrectIndexException {
        List<Integer> numbers = new List<>();
        assertEquals(true, numbers.isEmpty());
        for (Integer i = 0; i < 10; ++i) {
            numbers.add(i, 0);
        }
        assertEquals(false, numbers.isEmpty());
        for (int i = 0; i < 10; ++i) {
            numbers.pop(0);
        }
        assertEquals(true, numbers.isEmpty());
    }

    @Test
    public void addAndPop() throws ValueAlreadyContainedException, IncorrectIndexException {
        List<Integer> numbers = new List<>();
        for (Integer i = 0; i < 10; ++i) {
            numbers.add(i, 0);
        }
        for (Integer i = 9; i >= 0; --i) {
            assertEquals(i, numbers.pop(0));
        }
    }

    @Test
    public void peek() throws ValueAlreadyContainedException, IncorrectIndexException {
        List<Integer> numbers = new List<>();
        for (Integer i = 0; i < 10; ++i) {
            numbers.add(i, 0);
        }
        Integer expected = 9;
        for (int i = 0; i < 10; ++i) {
            assertEquals(expected, numbers.peek(i));
            expected--;
        }
    }
}