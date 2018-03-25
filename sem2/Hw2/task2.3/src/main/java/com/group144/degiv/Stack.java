package com.group144.degiv;

public interface Stack<T> {
    int getSize();
    boolean isEmpty();
    void push(T value);
    T pop();
}
