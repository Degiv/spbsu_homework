package com.group144.degiv;

import org.junit.Test;

import static org.junit.Assert.*;

public class UniqueListTest {

    @Test(expected = ValueAlreadyContainedException.class)
    public void addDuplicates() throws ValueAlreadyContainedException {
        UniqueList<Integer> numbers = new UniqueList<>();
        numbers.add(1, 0);
        numbers.add(1, 1);
    }

    @Test
    public void addUnique() throws ValueAlreadyContainedException, IncorrectIndexException {
        UniqueList<Integer> numbers = new UniqueList<>();
        numbers.add(1, 0);
        numbers.add(2, 1);
        numbers.add(3, 1);
        Integer expected = 1;
        assertEquals(expected, numbers.peek(0));
        expected = 3;
        assertEquals(expected, numbers.peek(1));
        expected = 2;
        assertEquals(expected, numbers.pop(2));
    }
}