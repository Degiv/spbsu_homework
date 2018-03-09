package com.group144.Degiv;

public class Main {
    public static void main(String args[]){
        List numbers = new List();
        for (int i = 0; i < 5; ++i){
            numbers.add(i, numbers.getSize());
        }

        for (int i = 0; i < 5; ++i){
            numbers.add(i, 0);
        }

        while (!numbers.isEmpty()){
            System.out.println(numbers.pop(0));
        }
    }
}
