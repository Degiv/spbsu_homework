package com.group144.Degiv;


public class Stack {

    private class StackElement {
        private int value;
        private StackElement next;

        StackElement(int value, StackElement next) {
            this.value = value;
            this.next = next;
        }

        public int getValue() {
            return value;
        }

        public StackElement getNext() {
            return next;
        }
    }

    private StackElement head = null;
    private int size = 0;

    public int GetSize() {
        return size;
    }

    public boolean IsEmpty() {
        return size == 0;
    }

    public void add(int value) {
        head = new StackElement(value, head);
        size += 1;
    }

    public int pop() {
	int result = -1;
	if (size == 0)
		return result;

        result = head.getValue();
        head = head.getNext();
        size -= 1;
        return result;
    }
}