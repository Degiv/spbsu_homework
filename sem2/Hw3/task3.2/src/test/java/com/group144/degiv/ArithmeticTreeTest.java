package com.group144.degiv;

import org.junit.Test;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

import static org.junit.Assert.*;

public class ArithmeticTreeTest {

    @Test
    public void calculate1() throws FileNotFoundException {
        File file = new File("D:/task3.2/src/test/resources/test1.txt");
        Scanner in = new Scanner(file);
        ArithmeticTree tree = new ArithmeticTree(in.nextLine());
        assertEquals(6, tree.calculate());
    }

    @Test
    public void calculate2() throws FileNotFoundException {
        File file = new File("D:/task3.2/src/test/resources/test2.txt");
        Scanner in = new Scanner(file);
        ArithmeticTree tree = new ArithmeticTree(in.nextLine());
        assertEquals(0, tree.calculate());
    }

    @Test
    public void calculate3() throws FileNotFoundException {
        File file = new File("D:/task3.2/src/test/resources/test3.txt");
        Scanner in = new Scanner(file);
        ArithmeticTree tree = new ArithmeticTree(in.nextLine());
        assertEquals(2, tree.calculate());
    }
}