package com.group144.degiv;

/**
 *class realized sparse vector
 */
public class SparseVector {
    private Node head;

    SparseVector() {
        head = null;
    }

    public Node getHead() {
        return head;
    }

    public boolean isNull() {
        return head == null;
    }

    public void setElement(int value, int index) {
        if (value == 0)
            return;

        if (isNull() || head.getIndex() > index) {
            head = new Node(value, index, head);
            return;
        }

        Node prev = head;
        while (prev.getNext() != null) {
            if (prev.getNext().getIndex() == index) {
                prev.getNext().setData(value);
                return;
            }

            if (prev.getNext().getIndex() > index) {
                Node newNode = new Node(value, index, prev.getNext());
                prev.setNext(newNode);
                return;
            }

            prev = prev.getNext();
        }
        Node newNode = new Node(value, index, null);
        prev.setNext(newNode);
    }

    /**
     * clones sparse vector
     * @return copy of vector
     */
    public SparseVector clone() {
        SparseVector newVector = new SparseVector();
        Node tmp = head;
        while (tmp != null) {
            newVector.setElement(tmp.getData(), tmp.getIndex());
            tmp = tmp.getNext();
        }
        return newVector;
    }

    /**
     * finds element by index
     * @param index index for search
     * @return value of element
     */
    public int find(int index) {
        Node tmp = head;
        while (tmp != null) {
            if (tmp.getIndex() == index)
                return tmp.getData();
            if (tmp.getIndex() > index)
                return 0;
            tmp = tmp.getNext();
        }
        return 0;
    }

    /**
     * addition of vectors
     * @param added added vector
     * @return result
     */
    public SparseVector addition(SparseVector added) {
        SparseVector result = new SparseVector();
        Node tmp = head;
        while (tmp != null) {
            result.setElement(added.find(tmp.getIndex()) + tmp.getData(), tmp.getIndex());
            tmp = tmp.getNext();
        }

        tmp = added.getHead();
        while (tmp != null) {
            if (find(tmp.getIndex()) == 0) {
                result.setElement(tmp.getData(), tmp.getIndex());
            }
            tmp = tmp.getNext();
        }

        return result;
    }

    /**
     * subtraction of vectors
     * @param subtrahend subtrahend vector
     * @return result
     */
    public SparseVector subtraction(SparseVector subtrahend) {
        SparseVector result = new SparseVector();
        Node tmp = head;
        while (tmp != null) {
            result.setElement(tmp.getData() - subtrahend.find(tmp.getIndex()), tmp.getIndex());
            tmp = tmp.getNext();
        }

        tmp = subtrahend.getHead();
        while (tmp != null) {
            if (find(tmp.getIndex()) == 0) {
                result.setElement(-tmp.getData(), tmp.getIndex());
            }
            tmp = tmp.getNext();
        }
        return result;
    }

    /**
     * dot product of vectors
     * @param factor vector
     * @return result
     */
    public int dotProduct(SparseVector factor) {
        int result = 0;
        Node tmp = head;
        while (tmp != null) {
            result += tmp.getData() * factor.find(tmp.getIndex());
            tmp = tmp.getNext();
        }

        return result;
    }

    /**
     * class realizing node of sparse vector
     */
    private class Node {
        private int data;
        private int index;
        private Node next;

        Node(int data, int index, Node next) {
            this.data = data;
            this.index = index;
            this.next = next;
        }

        public int getData() {
            return data;
        }

        public void setData(int data) {
            this.data = data;
        }

        public int getIndex() {
            return index;
        }

        public Node getNext() {
            return next;
        }

        public void setNext(Node next) {
            this.next = next;
        }
    }
}
