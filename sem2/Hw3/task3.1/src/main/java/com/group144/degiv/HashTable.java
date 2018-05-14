package com.group144.degiv;

import java.util.ArrayList;
import java.util.LinkedList;

/**
 * class realizing the hash-table
 */
public class HashTable {
    private ArrayList<LinkedList<String>> data;
    private HashFunction hashFunction;
    private int elementCounter = 0;
    private int conflictCounter = 0;

    HashTable(int size, HashFunction hashFunction) {
        data = new ArrayList<>(size);
        for (int i = 0; i < size; ++i) {
            data.add(new LinkedList<>());
        }
        this.hashFunction = hashFunction;
    }

    /**
     * adds new value in hash-table
     * @param value new value
     */
    public void add(String value) {
        int index = hashFunction.hash(value, data.size());
        if (data.get(index).size() == 1) {
            conflictCounter++;
        }
        data.get(index).add(value);
        elementCounter++;
    }

    /**
     * removes value from hash-table
     * @param value value to remove
     * @throws ElementNotFoundException
     */
    public void remove(String value) throws ElementNotFoundException {
        int index = hashFunction.hash(value, data.size());
        if (data.get(index).remove(value)) {
            if (data.get(index).size() == 1) {
                conflictCounter--;
            }
            elementCounter--;
        }
        else {
            throw new ElementNotFoundException();
        }
    }

    /**
     * returns true if table contains the value, returns false otherwise
     * @param value value to checking
     * @return true if table contains the value, return false otherwise
     */
    public boolean contains(String value) {
        return data.get(hashFunction.hash(value, data.size())).contains(value);
    }

    public int getElementCounter() {
        return elementCounter;
    }

    public int getConflictCounter() {
        return conflictCounter;
    }

    /**
     * returns hash-table load factor
     * @return hash-table load factor
     */
    public double loadFactor() {
        return (double) getElementCounter() / data.size();
    }

    public int getMaxListSize() {
        int result = 0;
        for (LinkedList current: data) {
            result = Math.max(result, current.size());
        }
        return result;
    }
}
