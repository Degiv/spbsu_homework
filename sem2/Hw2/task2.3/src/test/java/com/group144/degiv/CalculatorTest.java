package com.group144.degiv;

import org.junit.Test;

import static org.junit.Assert.*;

public class CalculatorTest {

    @Test
    public void calculate() throws WrongExpressionException, EmptyStackException {
        Calculator calculator = new Calculator();
        String expression = "2 2 + 4 *";
        assertEquals(16, calculator.calculate(expression));

        expression = "1 3 6 6 - + -";
        assertEquals(-2, calculator.calculate(expression));

        expression = "6 2 / 3 + 2 /";
        assertEquals(3, calculator.calculate(expression));

        expression = "1";
        assertEquals(1, calculator.calculate(expression));
    }
}