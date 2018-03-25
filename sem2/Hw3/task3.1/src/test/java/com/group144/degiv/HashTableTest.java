package com.group144.degiv;

import org.junit.Test;

import static org.junit.Assert.*;

public class HashTableTest {

    final int INITIAL_SIZE = 41;
    @Test
    public void add() {
        HashTable hashTable = new HashTable(INITIAL_SIZE, new PolynomialHashFunction());
        hashTable.add("qwerty");
        hashTable.add("asdf");
        hashTable.add("zxcvb");
        assertEquals(3, hashTable.getElementCounter());
    }

    @Test
    public void remove() throws ElementNotFoundException {
        HashTable hashTable = new HashTable(INITIAL_SIZE, new PolynomialHashFunction());
        hashTable.add("qwerty");
        hashTable.add("asdf");
        hashTable.add("zxcvb");
        hashTable.remove("qwerty");
        assertEquals(2, hashTable.getElementCounter());
    }

    @Test
    public void contains() throws ElementNotFoundException {
        HashTable hashTable = new HashTable(INITIAL_SIZE, new SumHashFunction());
        hashTable.add("qwerty");
        hashTable.add("asdf");
        hashTable.add("zxcvb");
        assertEquals(true, hashTable.contains("qwerty"));
        assertEquals(true, hashTable.contains("asdf"));
        assertEquals(true, hashTable.contains("zxcvb"));
        hashTable.remove("qwerty");
        assertEquals(false, hashTable.contains("qwerty"));
        assertEquals(false, hashTable.contains("ytrewq"));
        assertEquals(false, hashTable.contains("fdsa"));
    }
}