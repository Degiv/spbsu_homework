package com.group144.Degiv;

public class QuickSort implements Sorter{
    @Override
    public void sort(int[] arr) {
        recursiveSort(arr, 0, arr.length);
    }

    private void recursiveSort(int[] arr, int start, int end){
        if (end - start == 1)
            return;

        int i = start;
        int j = end - 1;
        int pivot = arr[(i + j) / 2];

        while (i <= j){
            while (arr[i] < pivot)
                ++i;
            while (arr[j] > pivot)
                --j;

            if (i <= j){
                swap(arr, i, j);
                ++i;
                --j;
            }
        }

        if (j > start)
            recursiveSort(arr, start, j + 1);

        if (i < end - 1)
            recursiveSort(arr, i, end);

    }

    private void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}