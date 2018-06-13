package com.group144.degiv;

public class ArrayStack<T> implements Stack<T> {
    private final int INITIAL_SIZE = 10;
    private int size = 0;
    private int capacity = INITIAL_SIZE;
    private T[] data = (T[]) new Object[capacity];
    @Override
    public int getSize() {
        return size;
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    @Override
    public void push(T value) {
        if (size == capacity)
            updateCapacity();

        data[size] = value;
        size++;
    }

    @Override
    public T pop() throws EmptyStackException {
        if (isEmpty()) {
            throw new EmptyStackException();
        }

        T result = data[size - 1];
        size--;
        if (size < capacity / 2 && capacity > INITIAL_SIZE)
            degradeCapacity();
        return result;
    }

    private void updateCapacity() {
        T[] tmp = (T[]) new Object[capacity * 2];
        for (int i = 0; i < capacity; ++i) {
            tmp[i] = data[i];
        }
        data = tmp;
        capacity *= 2;
    }

    private void degradeCapacity() {
        capacity /= 2;
        T[] tmp = (T[]) new Object[capacity];
        for (int i = 0; i < capacity; ++i) {
            tmp[i] = data[i];
        }
        data = tmp;
    }
}
