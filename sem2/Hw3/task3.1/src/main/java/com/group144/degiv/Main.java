package com.group144.degiv;

import java.io.*;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws ElementNotFoundException {
        Scanner in = new Scanner(System.in);
        final int INITIAL_SIZE = 41;
        HashTable hashTable = new HashTable(INITIAL_SIZE, getHashFunction(in));
        printMenu();
        String command = " ";
        while(!command.equals("exit")) {
            command = in.next();
            switch (command) {
                case "add":
                    hashTable.add(in.next());
                    break;
                case "remove":
                    hashTable.remove(in.next());
                    break;
                case "contains":
                    System.out.println(hashTable.contains(in.next()));
                    break;
                case"stats":
                    printStats(hashTable);
                    break;
                case "fill":
                    fillFromFile(hashTable);
                    break;
            }
        }
    }

    private static void fillFromFile(HashTable hashTable) {
        Scanner file;
        try {
            file = new Scanner(new FileInputStream("filename.txt"));
        } catch (FileNotFoundException exception) {
            System.out.println("File is not found.");
            return;
        }
        while (file.hasNext()) {
            hashTable.add(file.next());
        }
    }

    public static void printStats(HashTable hashTable) {
        System.out.print("Element number: ");
        System.out.println(hashTable.getElementCounter());
        System.out.print("Conflict number: ");
        System.out.println(hashTable.getConflictCounter());
        System.out.print("Load factor: ");
        System.out.println(hashTable.loadFactor());
        System.out.print("Max list size: ");
        System.out.println(hashTable.getMaxListSize());
    }

    public static void printMenu() {
        System.out.println("Hash table created.");
        System.out.println("Supported commands:");
        System.out.println("add <word> (adds word to table)");
        System.out.println("remove <word> (removes word from table)");
        System.out.println("contains <word> (returns true if word contains)");
        System.out.println("stats (shows statistic information)");
        System.out.println("fill (fills table from file)");
        System.out.println("exit (exit program)");
    }

    public static HashFunction getHashFunction(Scanner in) {
        System.out.println("Choose hash function:");
        System.out.println("polynomial");
        System.out.println("sum");
        System.out.println("xor");
        while (true) {
            switch (in.next()) {
                case "polynomial":
                    return new PolynomialHashFunction();
                case "sum":
                    return new SumHashFunction();
                case "xor":
                    return new XorHashFunction();
            }
            System.out.println("Wrong choice. Try again");
        }
    }
}
