package com.group144.degiv;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;

/**
 * AVL tree data structure
 * @param <T> type of values
 */
public class AVLTree<T extends Comparable<T>> implements Collection<T> {
    /**
     * class realizing tree node
     */
     public class Node {
        private T value;
        private int height;
        private Node left;
        private Node right;

        Node(T value) {
            this.value = value;
            height = 1;
            left = null;
            right = null;
        }

        public T getValue() {
            return value;
        }

        public Node getRight() {
            return right;
        }

        public Node getLeft() {
            return left;
        }
    }

    /**
     * root of tree
     */
    private Node root = null;
    /**
     * tree size
     */
    private int size = 0;

    /**
     * returns tree size
     * @return tree size
     */
    @Override
    public int size() {
        return size;
    }

    /**
     * emptiness checking
     * @return true if tree is empty and false otherwise
     */
    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    /**
     * checks if tree contains given value
     * @param value value to check
     * @return true if tree contains value and false otherwise
     */
    @Override
    public boolean contains(Object value) {
        return recursiveContains(root, (T) value);
    }

    /**
     * returns tree iterator
     * @return iterator
     */
    @Override
    public Iterator<T> iterator() {
        return new TreeIterator<>(this);
    }

    /**
     * makes object array of values stored in tree..
     * @return tree objects array
     */
    @Override
    public Object[] toArray() {
        ArrayList<T> result = new ArrayList<>();
        for (T current: this) {
            result.add(current);
        }
        return result.toArray();
    }


    /**
     * writes tree values in given array
     * @param a array to write in
     * @param <T1> type of array values
     * @return tree values array
     */
    @Override
    public <T1> T1[] toArray(T1[] a) {
        ArrayList<T1> data = new ArrayList<>();
        for (T current: this) {
            data.add((T1) current);
        }
        return data.toArray(a);
    }

    /**
     * adds value in tree
     * @param value value to add
     * @return true if value was added and false otherwise
     */
    @Override
    public boolean add(T value) {
        if (contains(value))
            return false;
        root = recursiveAdd(root, value);
        size++;
        return true;
    }

    /**
     * removes value from tree
     * @param value value to remove
     * @return true if value was removed and false otherwise
     */
    @Override
    public boolean remove(Object value) {
        if (!contains(value))
            return false;
        root = recursiveRemove(root, (T) value);
        size--;
        return true;
    }

    /**
     * checks if tree contains all values of given collection
     * @param collection to check
     * @return true if tree contains all values of collection
     */
    @Override
    public boolean containsAll(Collection<?> collection) {
        for (Object current: collection) {
            if (!contains(current))
                return false;
        }
        return true;
    }

    /**
     * adds all values of given collection in tree
     * @param collection collection to add
     * @return true if tree was changed and false otherwise
     */
    @Override
    public boolean addAll(Collection<? extends T> collection) {
        boolean result = false;
        for (T current: collection) {
            result |= add(current);
        }
        return result;
    }

    /**
     * removes all values of given collection from tree
     * @param collection to remove
     * @return true if tree was changed and false otherwise
     */
    @Override
    public boolean removeAll(Collection<?> collection) {
        boolean result = false;
        for (Object current: collection) {
            result |= remove(current);
        }
        return result;
    }

    /**
     * removes all values from tree except present in given collection
     * @param collection collection of values that will not be removed
     * @return true if tree was changed and false otherwise
     */
    @Override
    public boolean retainAll(Collection<?> collection) {
        boolean result = false;
        for (T current: this) {
            if (!collection.contains(current))
                result |= remove(current);
        }
        return result;
    }

    /**
     * clears tree
     */
    @Override
    public void clear() {
        root = null;
        size = 0;
    }

    /**
     * returns root
     * @return root
     */
    public Node getRoot() {
        return root;
    }

    private int balanceFactor(Node node) {
        if (node.left != null) {
            if (node.right != null)
                return node.left.height - node.right.height;
            else
                return node.left.height;
        }
        else {
            if (node.right != null)
                return -node.right.height;
            else
                return 0;
        }
    }

    private void updateHeight(Node node) {
        int leftHeight = 0;
        int rightHeight = 0;

        if (node.left != null)
            leftHeight = node.left.height;
        if (node.right != null)
            rightHeight = node.right.height;

        node.height = Math.max(rightHeight, leftHeight) + 1;
    }

    private Node rotateRight(Node node) {
        Node tmp = node.left;
        node.left = tmp.right;
        tmp.right = node;
        updateHeight(node);
        updateHeight(tmp);
        return tmp;
    }

    private Node rotateLeft(Node node) {
        Node tmp = node.right;
        node.right = tmp.left;
        tmp.left = node;
        updateHeight(node);
        updateHeight(tmp);
        return tmp;
    }

    private Node balance(Node node) {
        updateHeight(node);
        if (balanceFactor(node) == 2) {
            if (balanceFactor(node.left) < 0)
                node.left = rotateLeft(node.left);
            return rotateRight(node);
        }

        if (balanceFactor(node) == -2) {
            if (balanceFactor(node.right) > 0)
                node.right = rotateRight(node.right);
            return rotateLeft(node);
        }

        return node;
    }

    private Node recursiveAdd(Node node, T newValue) {
        if (node == null) {
            node = new Node(newValue);
            return node;
        }

        if (node.value == newValue)
            return node;

        if (node.value.compareTo(newValue) > 0)
            node.left = recursiveAdd(node.left, newValue);
        else
            node.right = recursiveAdd(node.right, newValue);

        return balance(node);
    }

    private Node findMax(Node node) {
        if (node.right == null)
            return node;
        else
            return findMax(node.right);
    }

    private Node removeMax(Node node) {
        if (node.right == null)
            return node.left;
        else
            node.right = removeMax(node.right);
        return balance(node);
    }

    private Node recursiveRemove(Node node, T value) {
        if (node == null)
            return node;

        if (node.value == value) {
            Node left = node.left;
            Node right = node.right;

            if (left == null)
                return right;

            Node maxNode = findMax(left);
            maxNode.left = removeMax(left);
            maxNode.right = right;
            return balance(maxNode);
        }

        if (node.value.compareTo(value) > 0)
            node.left = recursiveRemove(node.left, value);
        else
            node.right = recursiveRemove(node.right, value);

        return balance(node);
    }

    private boolean recursiveContains(Node node, T value) {
        if (node == null)
            return false;

        if (node.value == value)
            return true;

        if (node.value.compareTo(value) > 0)
            return recursiveContains(node.left, value);
        else
            return recursiveContains(node.right, value);
    }
}
