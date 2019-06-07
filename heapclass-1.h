// Copyright (c) 2019, Matthew Chalifoux.

#ifndef HEAPCLASS_H
#define HEAPCLASS_H
#include <iostream>
#include <iomanip>
using namespace std;
template<typename T>
class Heap{
    public:
        Heap();
        Heap(const Heap<T>& rhs);
        Heap<T>& operator =(const Heap<T>& rhs);
        ~Heap();
        unsigned int how_many();
        void insert(const T& insert_me);
        T Pop();
        bool is_empty() const;
        unsigned int size() const;
        unsigned int capacity() const;
        template<typename U>
        friend ostream& operator << (ostream& outs, const Heap<U>& print_me);
    private:
        T get_pop(T& capture);
        void adjust_tree_pop(T* root, unsigned int index = 0);
        void adjust_tree_insert(T* root, unsigned int index);
        void print(T* root, int level = 0, int i = 0, ostream& outs = cout)const;
        void print_tree(ostream& outs = cout) const;
        void print_tree(T* root, int level = 0, ostream& outs = cout) const;
//        bool is_leaf(unsigned int i) const;
//        unsigned int parent_index(unsigned int i) const;
//        unsigned int left_child_index(unsigned int i)const;
//        unsigned int right_child_index(unsigned int i) const;
//        unsigned int big_child_index(unsigned int i) const;
//        void swap_with_parent(unsigned int i);

        unsigned int cap;
        unsigned int sz;
        T *array;
};
#endif // HEAPCLASS_H
