package com.group144.degiv;

import java.util.Iterator;
import java.util.LinkedList;

public class TreeIterator<T extends Comparable<T>> implements Iterator<T> {
    private AVLTree.Node node;
    private LinkedList<AVLTree.Node> queue;

    TreeIterator(AVLTree<T> tree) {
        node = tree.getRoot();
        queue = new LinkedList<>();
        queue.addLast(tree.getRoot());
        if (tree.getRoot().getLeft() != null)
            queue.addLast(tree.getRoot().getLeft());
        if (tree.getRoot().getRight() != null)
            queue.addLast(tree.getRoot().getRight());
    }

    @Override
    public boolean hasNext() {
        return queue.size() > 1;
    }

    @Override
    public T next() {
        T result = (T) node.getValue();
        if (!hasNext())
            return result;
        queue.removeFirst();
        if (queue.peekFirst() == null)
            return result;
        node = queue.peekFirst();
        if (queue.peekFirst().getLeft() != null)
            queue.addLast(queue.peekFirst().getLeft());
        if (queue.peekFirst().getRight() != null)
            queue.addLast(queue.peekFirst().getRight());
        return result;
    }
}
