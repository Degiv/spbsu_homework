package com.group144.degiv;

public class Main {
    public static void main(String args[]) {
        Stack numbers = new Stack();

        for (int i = 0; i < 9; ++i) {
            numbers.add(i);
        }

        System.out.println(numbers.GetSize());

        for (int i = 0; i < 9; ++i) {
            System.out.println(numbers.pop());
        }

        System.out.println(numbers.GetSize());
    }
}