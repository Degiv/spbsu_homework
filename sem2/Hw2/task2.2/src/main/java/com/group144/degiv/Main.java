package com.group144.degiv;

import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(System.in);

        System.out.print("Enter n: ");
        int n = in.nextInt();
        int[][] numbers = new int[n][n];
        System.out.println("Enter n x n matrix:");
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                numbers[i][j] = in.nextInt();
            }
        }

        System.out.println("1. To console");
        System.out.println("2. To file output.txt");
        System.out.print("Enter 1 or 2 to print spiral:");
        switch(in.nextInt()) {
            case 1: {
                Outputter outputter = new OutputterSpiralConsole();
                outputter.outputSpiral(numbers);
                break;
            }
            case 2: {
                Outputter outputter = new OutputterSpiralFile();
                outputter.outputSpiral(numbers);
                break;
            }
        }
    }
}
