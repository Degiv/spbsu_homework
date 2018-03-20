package com.group144.degiv;

/**
 * Linked queue elements of which are arranged in descending order of priority
 *
 *  @param <T> type of values stored in priority queue
 */
public class LinkedPriorityQueue<T> implements PriorityQueue<T> {
    /**
     * Class realizing element of priority queue
     */
    private class Node {
        private T value;
        private int priority;
        private Node next;

        Node(T value, int priority, Node next) {
            this.value = value;
            this.priority = priority;
            this.next = next;
        }

        public T getValue() {
            return value;
        }
        public int getPriority() {
            return priority;
        }
        public Node getNext() {
            return next;
        }
        public void setNext(Node next) {
            this.next = next;
        }
    }

    /**
     * First element in queue
     */
    private Node head = null;

    /**
     * Returns true if queue is empty false otherwise
     *
     * @return true if queue is empty false otherwise
     */
    private boolean isEmpty() {
        return head == null;
    }

    /**
     * Adds value in queue according to its priority
     *
     * @param value added value
     * @param priority priority of value
     */
    @Override
    public void enqueue(T value, int priority) {
        if (isEmpty()) {
            head = new Node(value, priority, null);
            return;
        }

        if (head.getPriority() < priority) {
            head = new Node(value, priority, head);
            return;
        }

        Node newNode = new Node(value, priority, null);
        Node tmp = head;

        while (tmp.getNext() != null && tmp.getNext().getPriority() > newNode.getPriority()) {
            tmp = tmp.getNext();
        }

        newNode.setNext(tmp.getNext());
        tmp.setNext(newNode);
    }

    /**
     * returns value with the highest priority
     *
     * @throws EmptyQueueException if queue is empty
     * @return value with the highest priority
     */
    @Override
    public T dequeue() {
        if (isEmpty()) {
            throw new EmptyQueueException();
        }

        T result = head.getValue();
        head = head.getNext();
        return result;
    }
}
