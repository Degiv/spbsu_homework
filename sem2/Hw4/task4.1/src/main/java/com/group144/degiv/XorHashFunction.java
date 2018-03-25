package com.group144.degiv;

public class XorHashFunction implements HashFunction {
    @Override
    public int hash(String value, int mod) {
        int result = 0;
        for (char current: value.toCharArray()) {
            result = result ^ current;
        }
        return result % mod;
    }
}
