package com.group144.degiv;

public class LinkedStack<T> implements Stack<T> {
    private class Node {
        private T value;
        private Node next;

        Node(T value, Node next) {
            this.next = next;
            this.value = value;
        }

        public T getValue() {
            return value;
        }
        public Node getNext() {
            return next;
        }
    }

    private Node head = null;
    private int size = 0;
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
        head = new Node(value, head);
        size++;
    }

    @Override
    public T pop() throws NullPointerException{
        T result = head.getValue();
        head = head.getNext();
        size--;
        return result;
    }
}
