#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdexcept>

class ArrayList {
private:
    int *arr;
    int size;
    int capacity;
    void resize(int new_capacity);

public:
    ArrayList(int initial_capacity = 10);
    ~ArrayList();
    void add(int value);
    void insert(int index, int value);
    void remove(int index);
    int get(int index) const;
    int getSize() const;
    int getCapacity() const;
    void print() const;
};

#endif // ARRAYLIST_H
