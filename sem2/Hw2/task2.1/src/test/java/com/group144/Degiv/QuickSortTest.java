package com.group144.degiv;

import org.junit.Test;
import static org.junit.Assert.*;

public class QuickSortTest {

    @Test
    public void sortSorted() {
        int[] actuals = {1, 3, 4, 7, 11};
        int[] expecteds = {1, 3, 4, 7, 11};
        Sorter sorter = new QuickSort();
        sorter.sort(actuals);
        assertArrayEquals(expecteds, actuals);
    }

    @Test
    public void sortReversed() {
        int[] actuals = {11, 7, 4, 3, 1};
        int[] expecteds = {1, 3, 4, 7, 11};
        Sorter sorter = new QuickSort();
        sorter.sort(actuals);
        assertArrayEquals(expecteds, actuals);
    }

    @Test
    public void sortDuplicates() {
        int[] actuals = {1, 3, 1, 6, 3, 1};
        int[] expecteds = {1, 1, 1, 3, 3, 6};
        Sorter sorter = new QuickSort();
        sorter.sort(actuals);
        assertArrayEquals(expecteds, actuals);
    }

    @Test
    public void sortSingle() {
        int[] actuals = {17};
        int[] expecteds = {17};
        Sorter sorter = new QuickSort();
        sorter.sort(actuals);
        assertArrayEquals(expecteds, actuals);
    }
}