package com.group144.degiv;

import org.junit.Test;
import static org.junit.Assert.*;
import java.io.*;
import java.util.Scanner;

public class OutputterTest {
    @Test
    public void consolePrint() throws FileNotFoundException {
        ByteArrayOutputStream actual = new ByteArrayOutputStream();
        System.setOut(new PrintStream(actual));

        int[][] numbers = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        Outputter outputter = new OutputterSpiralConsole();
        outputter.outputSpiral(numbers);

        String expected = "5 2 3 6 9 8 7 4 1 ";
        assertEquals(expected, actual.toString());
    }

    @Test
    public void OneElementMatrix() throws FileNotFoundException {
        ByteArrayOutputStream arrayOutputStream = new ByteArrayOutputStream();
        System.setOut(new PrintStream(arrayOutputStream));

        int[][] numbers = {{1}};
        Outputter outputter = new OutputterSpiralConsole();
        outputter.outputSpiral(numbers);

        String answer = "1 ";
        assertEquals(answer, arrayOutputStream.toString());
    }

    @Test
    public void filePrint() throws FileNotFoundException {
        int[][] numbers = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        Outputter outputter = new OutputterSpiralFile();
        outputter.outputSpiral(numbers);

        Scanner file = new Scanner(new File("output.txt"));
        file.useDelimiter("\n");

        String answer = "5 2 3 6 9 8 7 4 1 ";
        assertEquals(answer, file.nextLine());
    }
}