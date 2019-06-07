// Copyright (c) 2019, Matthew Chalifoux.

#include "heapclass.cpp"
template <typename T>
struct info{
    T item;
    int priority;

    info();
    info(T i, int p);
    template<typename U>
    friend ostream& operator <<(ostream& outs, const info<U>& print_me);
    template<typename U>
    friend bool operator >(const info<U>& lhs, const info<U>& rhs);
};
template <typename T>
class PQueue
{
public:
    PQueue();
    ~PQueue();

    bool insert(const T& value, int p);
    T Pop();

    bool is_empty() const;
    int size() const;
    void print_tree() const;
    template<typename U>
    friend ostream& operator <<(ostream& outs, const PQueue<U>& print_me);

private:
    Heap<info<T> > heap;

};
int main()
{
    PQueue<int> test;
    test.insert(145,18);
    test.insert(178,25);
    cout << test;
    return 0;
}
template<typename T>
info<T>::info(T i, int p){
    item = i;
    priority = p;
}
template<typename T>
info<T>::info(){
    item = T();
    priority = int();
}
template<typename T>
PQueue<T>::PQueue(){

}
template<typename T>
PQueue<T>::~PQueue(){

}
template<typename T>
bool PQueue<T>::insert(const T& value, int p){
    info<T> sub(value,p);
    heap.insert(sub);
}
template<typename U>
bool operator >(const info<U>& lhs, const info<U>& rhs){
    cout << "^&^&^&^&^&" << endl;
    cout << "lhs.priority = " << lhs.priority << endl;
    cout << "rhs.priority = " << rhs.priority << endl;
    int l = lhs.priority;
    int r = rhs.priority;
//    if(r > l){
//        cout << "HERERE" << endl;
//        return true;
//    }
    if(l < r){
        cout << "#$$$##$$$$$$$###" << endl;
        //return true;
    }
}
template<typename U>
ostream& operator <<(ostream& outs, const info<U>& print_me){
    cout << print_me.item << " / " << print_me.priority << endl;
}
template<typename U>
ostream& operator <<(ostream& outs, const PQueue<U>& print_me){
    print_me.print_tree();
}
template<typename T>
void PQueue<T>::print_tree() const{
    cout << heap;
}
