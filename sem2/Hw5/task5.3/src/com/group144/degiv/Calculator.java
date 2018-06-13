package com.group144.degiv;

public class Calculator {

    private double firstOperand = 0.0;
    private double secondOperand = 0.0;
    private Operation operation = Operation.ADD;
    private State state = State.RESULT_OUTPUTTED;

    public enum Operation {ADD, SUB, MULT, DIV}
    private enum State {RESULT_OUTPUTTED, OPERATION_INPUTTED, FIRST_OPERAND_INPUTTED, SECOND_OPERAND_INPUTTED}

    /**
     * calculates operation
     */
    private void calculate() {
        switch (operation) {
            case ADD:
                firstOperand = firstOperand + secondOperand;
                break;
            case SUB:
                firstOperand = firstOperand - secondOperand;
                break;
            case MULT:
                firstOperand = firstOperand * secondOperand;
                break;
            case DIV:
                firstOperand = firstOperand / secondOperand;
                break;
        }
    }

    /**
     * action when number button pressed
     *
     * @param number number was pressed
     */
    public void numberPressed(int number) {
        switch (state) {
            case RESULT_OUTPUTTED:
                firstOperand = number;
                state = State.FIRST_OPERAND_INPUTTED;
                break;
            case OPERATION_INPUTTED:
                secondOperand = number;
                state = State.SECOND_OPERAND_INPUTTED;
                break;
            case FIRST_OPERAND_INPUTTED:
                firstOperand = firstOperand * 10 + number * (firstOperand < 0 ? -1 : 1);
                break;
            case SECOND_OPERAND_INPUTTED:
                secondOperand = secondOperand * 10 + number * (secondOperand < 0 ? -1 : 1);
                break;
        }
    }

    /**
     * action when operation button pressed
     *
     * @param operation operation was pressed
     */
    public void operationPressed(Operation operation) {
        switch (state) {
            case RESULT_OUTPUTTED:
            case FIRST_OPERAND_INPUTTED:
                secondOperand = firstOperand;
                break;
            case SECOND_OPERAND_INPUTTED:
                calculate();
                secondOperand = firstOperand;
                break;
        }
        this.operation = operation;
        state = State.OPERATION_INPUTTED;
    }

    /**
     * action when equals button pressed
     */
    public void equalsPressed() {
        if (state == State.OPERATION_INPUTTED || state == State.SECOND_OPERAND_INPUTTED) {
            calculate();
            state = State.RESULT_OUTPUTTED;
        }
    }

    /**
     * action when clear button pressed
     */
    public void clearPressed() {
        switch (state) {
            case RESULT_OUTPUTTED:
            case FIRST_OPERAND_INPUTTED:
                firstOperand = 0;
                break;
            case SECOND_OPERAND_INPUTTED:
            case OPERATION_INPUTTED:
                secondOperand = 0;
                break;
        }
    }

    /**
     * action when all clear button pressed
     */
    public void allClearPressed() {
        firstOperand = 0;
        secondOperand = 0;
        state = State.RESULT_OUTPUTTED;
    }

    /**
     * action when sign-changing button pressed
     */
    public void signChangingPressed() {
        switch (state) {
            case RESULT_OUTPUTTED:
                firstOperand = -firstOperand;
                state = State.FIRST_OPERAND_INPUTTED;
                break;
            case OPERATION_INPUTTED:
                secondOperand = -firstOperand;
                state = State.SECOND_OPERAND_INPUTTED;
                break;
            case FIRST_OPERAND_INPUTTED:
                firstOperand = -firstOperand;
                break;
            case SECOND_OPERAND_INPUTTED:
                secondOperand = -secondOperand;
                break;
        }
    }

    /**
     * return value for calculator screen
     *
     * @return value for calculator screen
     */
    public String display() {
        String result;
        if (state == State.RESULT_OUTPUTTED || state == State.FIRST_OPERAND_INPUTTED) {
            result = Double.toString(firstOperand);
        } else {
            result = Double.toString(secondOperand);
        }
        if (result.endsWith(".0")) {
            result = result.substring(0, result.length() - 2);
        }
        return result;
    }
}