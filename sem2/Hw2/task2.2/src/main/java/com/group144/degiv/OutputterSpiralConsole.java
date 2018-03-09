package com.group144.degiv;

public class OutputterSpiralConsole extends OutputterSpiral{
    @Override
    public void outputSpiral(int[][] numbers) {
        super.outputSpiral(numbers, System.out);
    }
}
