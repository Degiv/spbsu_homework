package com.group144.degiv;

/**
 * priority queue interface
 *
 * @param <T> type of values stored in priority queue
 */
public interface PriorityQueue<T> {
    void enqueue(T value, int priority);
    T dequeue();
}
