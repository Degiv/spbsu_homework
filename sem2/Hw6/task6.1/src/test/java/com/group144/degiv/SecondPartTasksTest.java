package com.group144.degiv;

import org.junit.Test;

import java.io.*;
import java.nio.file.*;
import java.util.*;

import static org.junit.Assert.*;
import static com.group144.degiv.SecondPartTasks.*;

public class SecondPartTasksTest {
    @Test
    public void testFindQuotes() throws IOException {
        File file1 = new File("file1");
        File file2 = new File("file2");
        File file3 = new File("file3");
        assertTrue(file1.createNewFile());
        assertTrue(file2.createNewFile());
        assertTrue(file3.createNewFile());
        Files.write(Paths.get(file1.getPath()), Arrays.asList("qwe", "def", "ghi"));
        Files.write(Paths.get(file2.getPath()), Arrays.asList("123", "426", "789"));
        Files.write(Paths.get(file3.getPath()), Arrays.asList("abc", "322", "adg"));
        assertEquals(Arrays.asList("123", "426", "322"), findQuotes(Arrays.asList(file1.getPath(), file2.getPath(), file3.getPath()), "2"));
        assertEquals(Arrays.asList("abc", "abc", "adg"), findQuotes(Arrays.asList(file1.getPath(), file2.getPath(), file3.getPath()), "a"));
        assertTrue(file1.delete());
        assertTrue(file2.delete());
        assertTrue(file3.delete());
    }

    @Test
    public void testPiDividedBy4() {
        double approximatePi = piDividedBy4() * 4;
        assertEquals(Math.PI, approximatePi, 1e-3);
    }

    @Test
    public void testFindPrinter() {
        Map<String, List<String>> data = new TreeMap<>();
        data.put("You", Collections.emptyList());
        data.put("Purity Ring", Arrays.asList("Another Eternity", "Shrines"));
        data.put("Arthur Conan Doyle", Collections.singletonList("The most greatest and amazingest adventures of Sherlock Holmes and his gorgeous friend Dr Wutson."));
        assertEquals("Arthur Conan Doyle", findPrinter(data));
    }

    @Test
    public void testCalculateGlobalOrder() {
        Map<String, Integer> order1 = new TreeMap<>();
        order1.put("qwer", 111);
        order1.put("tyu", 77);
        order1.put("iop", 50);
        Map<String, Integer> order2 = new TreeMap<>();
        order2.put("asd", 10);
        order2.put("fghj", 8);
        order2.put("iop", 150);
        Map<String, Integer> order3 = new TreeMap<>();

        Map<String, Integer> expected = new TreeMap<>();
        expected.put("qwer", 111);
        expected.put("tyu", 77);
        expected.put("iop", 200);
        expected.put("asd", 10);
        expected.put("fghj", 8);
        Map<String, Integer> result = calculateGlobalOrder(Arrays.asList(order1, order2, order3));
        assertEquals(expected, result);
    }
}