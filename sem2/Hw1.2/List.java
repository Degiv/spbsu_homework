package com.group144.Degiv;

public class List {

    private class ListElement {
        private int value;
        private ListElement next;

        ListElement(int value, ListElement next){
            this.value = value;
            this.next = next;
        }

        public int getValue(){
            return value;
        }

        public ListElement getNext(){
            return next;
        }

        public void setNext(ListElement next){
            this.next = next;
        }
    }

    private ListElement head = new ListElement(0, null);
    private int size = 0;

    public int getSize(){
        return size;
    }

    public boolean isEmpty(){
        return size == 0;
    }

    public void add(int value, int index){
        if (index > size)
            return;

        ListElement tmp = head;
        for (int i = 0; i < index; ++i){
            tmp = tmp.getNext();
        }

        ListElement newElement = new ListElement(value, tmp.next);
        tmp.setNext(newElement);
        size++;
    }

    public int pop(int index){
        if (index >= size)
            return -1;

        ListElement tmp = head;
        for (int i = 0; i < index; ++i){
            tmp = tmp.getNext();
        }

        int result = tmp.getNext().getValue();
        tmp.setNext(tmp.getNext().getNext());
        size--;
        return result;
    }

    public int peek(int index){
        if (index >= size)
            return -1;

        ListElement tmp = head;
        for (int i = 0; i <= index; ++i){
            tmp = tmp.getNext();
        }

        return tmp.getValue();
    }
}
