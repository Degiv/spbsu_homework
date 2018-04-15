package com.group144.degiv;

import java.io.PrintStream;

abstract class OutputterSpiral implements Outputter {
    void outputSpiral(int[][] numbers, PrintStream stream) {
        int n = numbers.length;
        int firstIndex = n / 2;
        stream.print(numbers[firstIndex][firstIndex] + " ");
        int leftBorder = firstIndex;
        int upBorder = firstIndex - 1;
        int rightBorder = firstIndex;
        int downBorder = firstIndex;
        int i = firstIndex;
        int j = firstIndex - 1;

        while (j >= 0) {
            while (i <= rightBorder) {
                stream.print(numbers[j][i] + " ");
                i++;
            }
            rightBorder++;

            while (j <= downBorder) {
                stream.print(numbers[j][i] + " ");
                j++;
            }
            downBorder++;

            while (i >= leftBorder) {
                stream.print(numbers[j][i] + " ");
                i--;
            }
            leftBorder--;

            while (j >= upBorder) {
                stream.print(numbers[j][i] + " ");
                j--;
            }
            upBorder--;
        }
    }
}
