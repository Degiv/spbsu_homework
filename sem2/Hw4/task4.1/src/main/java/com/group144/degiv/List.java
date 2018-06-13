package com.group144.degiv;

/**
 * Simple Linked List
 *
 * @param <T> type of value
 */
public class List<T> {
    /**
     * Class realizing list element
     */
    public class ListElement {
        private T value;
        private ListElement next;

        ListElement(T value, ListElement next) {
            this.value = value;
            this.next = next;
        }

        public T getValue() {
            return value;
        }

        public ListElement getNext() {
            return next;
        }

        public void setNext(ListElement next) {
            this.next = next;
        }
    }

    /**
     * first list element
     */
    private ListElement head = null;
    private int size = 0;

    /**
     * returns size of list
     *
     * @return size of list
     */
    public int getSize() {
        return size;
    }

    public ListElement getHead() {
        return head;
    }

    /**
     * check list for emptiness
     *
     * @return true if list is empty and false otherwise
     */
    public boolean isEmpty() {
        return size == 0;
    }

    /**
     * adds new value to list
     *
     * @param value new value
     * @param index new value index
     */
    public void add(T value, int index) throws ValueAlreadyContainedException {
        if (index > size)
            return;

        if (index == 0) {
            head = new ListElement(value, head);
            size++;
            return;
        }

        ListElement tmp = head;
        for (int i = 0; i < index - 1; ++i) {
            tmp = tmp.getNext();
        }

        ListElement newElement = new ListElement(value, tmp.next);
        tmp.setNext(newElement);
        size++;
    }

    /**
     * returns value with given index and deletes it from list
     *
     * @param index index of element should be popped
     * @return value of element should be popped
     * @throws IncorrectIndexException if index is out of range
     */
    public T pop(int index) throws IncorrectIndexException {
        if (index >= size)
            throw new IncorrectIndexException();

        if (index == 0) {
            T result = head.getValue();
            head = head.getNext();
            size--;
            return result;
        }

        ListElement tmp = head;
        for (int i = 0; i < index - 1; ++i) {
            tmp = tmp.getNext();
        }

        T result = tmp.getNext().getValue();
        tmp.setNext(tmp.getNext().getNext());
        size--;
        return result;
    }

    /**
     * returns value with given index
     *
     * @param index index of element should be peeked
     * @return value of element should be peeked
     * @throws IncorrectIndexException if index is out of range
     */
    public T peek(int index) throws IncorrectIndexException {
        if (index >= size)
            throw new IncorrectIndexException();

        ListElement tmp = head;
        for (int i = 0; i < index; ++i) {
            tmp = tmp.getNext();
        }

        return tmp.getValue();
    }
}