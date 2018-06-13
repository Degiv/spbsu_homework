package com.group144.degiv;

/**
 * List without duplicates
 *
 * @param <T> type of value
 */
public class UniqueList<T> extends List<T> {
    /**
     * adds new value to list
     *
     * @param value new value
     * @param index new value index
     * @throws ValueAlreadyContainedException if value already contained
     */
    @Override
    public void add(T value, int index) throws ValueAlreadyContainedException {
        if (find(value)) {
            throw new ValueAlreadyContainedException();
        }
        super.add(value, index);
    }

    /**
     * checks the availability of given value
     *
     * @param value value for checking
     * @return true if value is found and false otherwise
     */
    public boolean find(T value) {
        ListElement tmp = getHead();
        for (int i = 0; i < getSize(); ++i) {
            if (tmp.getValue() == value) {
                return true;
            }
            tmp = tmp.getNext();
        }
        return false;
    }
}
