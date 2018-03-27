package com.group144.degiv;

public class ArithmeticTree {
    private class Node {
        private char symbol = '\0';
        private Node left = null;
        private Node right = null;

        public void print() {
            System.out.print(symbol);
        }

        public int calculate() {
            if (isNumber(symbol))
                return symbol - '0';
            else {
                int left = this.left.calculate();
                int right = this.right.calculate();
                int result = 0;
                switch (symbol) {
                    case '+':
                        result = left + right;
                        break;
                    case '-':
                        result = left - right;
                        break;
                    case '*':
                        result = left * right;
                        break;
                    case '/':
                        result = left / right;
                        break;
                }
                return result;
            }
        }
    }

    private Node root = null;
    private int index = 0;
    private String expression;

    ArithmeticTree(String expression) {
        this.expression = expression;
        root = build(root);
    }



    public int calculate() {
        return root.calculate();
    }

    public void showTree() {
        showTreeRecursive(root);
    }

    private void showTreeRecursive(Node current) {
        if (current.left != null) {
            System.out.print('(');
            current.print();
            System.out.print(' ');
            showTreeRecursive(current.left);
            System.out.print(' ');
            showTreeRecursive(current.right);
            System.out.print(')');
        }
        else {
            current.print();
        }
    }

    private Node build(Node current) {
        current = new Node();
        if (expression.charAt(index) == '(') {
            index++;
            current.symbol = expression.charAt(index++);
            index++;
            current.left = build(current.left);
            index++;
            current.right = build(current.right);
            index++;
        }
        else {
            current.symbol = expression.charAt(index++);
        }
        return current;
    }

    public static boolean isNumber(char symbol)
    {
        return symbol >= '0' && symbol <= '9';
    }
}
