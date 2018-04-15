package com.group144.degiv;

import java.io.FileNotFoundException;
import java.io.PrintStream;

public class OutputterSpiralFile extends OutputterSpiral {
    @Override
    public void outputSpiral(int[][] numbers) throws FileNotFoundException {
        super.outputSpiral(numbers, new PrintStream("output.txt"));
    }
}
