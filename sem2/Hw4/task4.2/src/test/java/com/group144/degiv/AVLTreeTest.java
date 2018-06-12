package com.group144.degiv;

import org.junit.Test;

import java.util.ArrayList;
import java.util.Iterator;
import static org.junit.Assert.*;

public class AVLTreeTest {
    @Test
    public void size() {
        AVLTree<Integer> tree = new AVLTree<>();
        tree.add(1);
        assertEquals(1, tree.size());
        for (Integer i = 0; i < 10; ++i)
            tree.add(i);
        assertEquals(10, tree.size());
    }

    @Test
    public void isEmpty() {
        AVLTree<Integer> tree = new AVLTree<>();
        assertEquals(true, tree.isEmpty());
        tree.add(1);
        assertEquals(false, tree.isEmpty());
        tree.remove(1);
        assertEquals(true, tree.isEmpty());
    }

    @Test
    public void contains() {
        AVLTree<Integer> tree = new AVLTree<>();
        tree.add(5);
        assertEquals(true, tree.contains(5));
        for (Integer i = 0; i < 5; ++i)
            assertEquals(false, tree.contains(i));
    }

    @Test
    public void iterator() {
        AVLTree<Integer> tree = new AVLTree<>();
        for (Integer i = 0; i < 5; ++i)
            tree.add(i);
        Iterator<Integer> iterator = tree.iterator();
        assertEquals((Integer) 1, iterator.next());
        assertEquals((Integer) 0, iterator.next());
        assertEquals((Integer) 3, iterator.next());
        assertEquals((Integer) 2, iterator.next());
        assertEquals((Integer) 4, iterator.next());
    }

    @Test
    public void clear() {
        AVLTree<Integer> tree = new AVLTree<>();
        tree.add(1);
        tree.add(3);
        tree.add(120);
        tree.clear();
        assertEquals(true, tree.isEmpty());
    }

    @Test
    public void retainAll() {
        AVLTree<Integer> tree = new AVLTree<>();
        ArrayList<Integer> collection = new ArrayList<>();
        for (Integer i = 0; i < 10; ++i) {
            tree.add(i);
            collection.add(i + 5);
        }
        tree.retainAll(collection);
        assertEquals(5, tree.size());
        Iterator<Integer> iterator = tree.iterator();
        assertEquals((Integer) 7, iterator.next());
        assertEquals((Integer) 5, iterator.next());
        assertEquals((Integer) 8, iterator.next());
        assertEquals((Integer) 6, iterator.next());
        assertEquals((Integer) 9, iterator.next());
    }
}