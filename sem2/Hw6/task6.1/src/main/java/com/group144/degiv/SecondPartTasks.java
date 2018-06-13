package com.group144.degiv;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public final class SecondPartTasks {
    // Найти строки из переданных файлов, в которых встречается указанная подстрока.
    public static List<String> findQuotes(List<String> paths, CharSequence sequence) {
        return paths.stream().map(filename -> fileContainsString(filename, sequence))
                .flatMap(List::stream)
                .collect(Collectors.toList());
    }

    // В квадрат с длиной стороны 1 вписана мишень.
    // Стрелок атакует мишень и каждый раз попадает в произвольную точку квадрата.
    // Надо промоделировать этот процесс с помощью класса java.util.Random и посчитать, какова вероятность попасть в мишень.
    public static double piDividedBy4() {
        Random rand = new Random();
        final int ATTEMPTS = 10000000;
        long hit = IntStream.range(1, ATTEMPTS).boxed()
                .filter(x -> checkSuccess(rand))
                .count();
        return ((double)hit) / ATTEMPTS;
    }

    // Дано отображение из имени автора в список с содержанием его произведений.
    // Надо вычислить, чья общая длина произведений наибольшая.
    public static String findPrinter(Map<String, List<String>> compositions) {
        List<Note> notes = new ArrayList<>();
        for (String author : compositions.keySet())
            notes.add(new Note(author, compositions.get(author)));
        Note noneResult = new Note("", Collections.emptyList());
        Note result = notes.stream().max(Comparator.comparingInt(Note::getSummaryLength)).orElse(noneResult);
        return result.author;
    }

    // Вы крупный поставщик продуктов. Каждая торговая сеть делает вам заказ в виде Map<Товар, Количество>.
    // Необходимо вычислить, какой товар и в каком количестве надо поставить.
    public static Map<String, Integer> calculateGlobalOrder(List<Map<String, Integer>> orders) {
        return orders.stream().flatMap(map -> map.entrySet().stream()).collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue, Integer::sum));
    }

    private static boolean checkSuccess(Random rand) {
        final double RADIUS = 0.5;
        double x = rand.nextDouble() % 1 - RADIUS;
        double y = rand.nextDouble() % 1 - RADIUS;
        return x * x + y * y <= RADIUS * RADIUS;
    }

    private SecondPartTasks() {}

    private static List<String> fileContainsString(String filename, CharSequence sequence) {
        try {
            List<String> lines = Files.readAllLines(Paths.get(filename));
            return lines.stream().filter(s -> s.contains(sequence))
                    .collect(Collectors.toList());
        } catch (IOException e) {
            return Collections.emptyList();
        }
    }

    private static class Note {
        private String author = null;
        private List<String> compositions = null;

        private Note(String author, List<String> compositions) {
            this.author = author;
            this.compositions = compositions;
        }

        private int getSummaryLength() {
            return compositions.stream().mapToInt(String::length).sum();
        }
    }
}