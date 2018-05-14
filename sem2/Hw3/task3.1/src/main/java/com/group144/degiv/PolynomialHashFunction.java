package com.group144.degiv;

public class PolynomialHashFunction implements HashFunction {
    @Override
    public int hash(String value, int mod) {
        final int QUOTIENT = 31;
        int result = 0;
        for (char current: value.toCharArray()) {
            result = (result * QUOTIENT + current) % mod;
        }
        return result;
    }
}
