package com.group144.degiv;

import org.junit.Test;

import static org.junit.Assert.*;

public class SparseVectorTest {

    @Test
    public void isNull() {
        SparseVector vector = new SparseVector();
        assertEquals(true, vector.isNull());
        vector.setElement(1, 0);
        assertEquals(false, vector.isNull());
    }

    @Test
    public void addition() {
        SparseVector vector1 = new SparseVector();
        SparseVector vector2 = new SparseVector();
        vector1.setElement(1, 0);
        vector2.setElement(2, 1);
        vector2.setElement(2, 0);
        SparseVector sum = vector1.addition(vector2);
        assertEquals(3, sum.find(0));
        assertEquals(2, sum.find(1));
    }

    @Test
    public void subtraction() {
        SparseVector vector1 = new SparseVector();
        SparseVector vector2 = new SparseVector();
        vector1.setElement(1, 0);
        vector2.setElement(2, 1);
        vector2.setElement(2, 0);
        SparseVector result = vector1.subtraction(vector2);
        assertEquals(-1, result.find(0));
        assertEquals(-2, result.find(1));
    }
}