package com.group144.degiv;


public class Calculator {
    public int calculate(String expression) throws WrongExpressionException {
        Stack<Integer> operands = new LinkedStack<>();
        //Stack<Integer> operands = new ArrayStack<>();

        int index = 0;
        while (index < expression.length()) {
            while (expression.charAt(index) == ' ' && index < expression.length())
                index++;
            if (isNumber(expression.charAt(index)))
                operands.push(expression.charAt(index) - '0');
            else {
                int result = operands.pop();
                switch (expression.charAt(index)) {
                    case '+':
                        result += operands.pop();
                        break;
                    case '-':
                        result = operands.pop() - result;
                        break;
                    case '*':
                        result *= operands.pop();
                        break;
                    case '/':
                        result = operands.pop() / result;
                        break;
                    default:
                        throw new WrongExpressionException();
                }
                operands.push(result);
            }
            index++;
        }

        if (operands.getSize() == 1)
            return operands.pop();
        else
            throw new WrongExpressionException();
    }

    private boolean isNumber(char symbol) {
        return symbol >= '0' && symbol <= '9';
    }
}
