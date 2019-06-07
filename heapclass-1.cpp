// Copyright (c) 2019, Matthew Chalifoux.

#include "heapclass.h"

template<typename T>
Heap<T>::Heap(){
    array = NULL;
    sz = 0;
}
template<typename T>
Heap<T>::~Heap(){
    delete []array;
}
template<typename T>
ostream& operator <<(ostream& outs, const Heap<T>& tree){
    //cout << "Here" << endl;
    tree.print_tree();
}
template<typename T>
void Heap<T>::print_tree(ostream& outs) const{
    //outs << "Here2" << endl;
    if(array == NULL){
        return;
    }
    print_tree(array);
}
template<typename T>
Heap<T>& Heap<T>::operator =(const Heap<T>& rhs){
    //cout << "Here4" << endl;
    sz = rhs.sz;
    array = new T[rhs.sz];
    for(unsigned int i = 0; i < rhs.sz; ++i){
        array[i] = rhs.array[i];
    }
}
template<typename T>
Heap<T>::Heap(const Heap<T>& rhs){
    //cout << "Here5" << endl;
    sz = rhs.sz;
    array = new T[rhs.sz];
    for(unsigned int i = 0; i < rhs.sz; ++i){
        array[i] = rhs.array[i];
    }
}
template<typename T>
void Heap<T>::print(T* root, int level, int i, ostream& outs)const{
    if(((2*i) + 2) <= sz - 1){
        print(root,level + 1,i*2 + 2);
    }
    outs << setw(level*4) << root[i] << endl;
    if(((2*i) + 1) <= sz - 1){
        print(root,level + 1,i*2 + 1);
    }
}
template<typename T>
void Heap<T>::print_tree(T* root, int level, ostream& outs) const{
    //outs << "Here3" << endl;
    print(root);
}
template<typename T>
void Heap<T>::insert(const T &insert_me){
    if(array == NULL){
        sz = 1;
        cap = sz*2;
        array = new T[sz];
        array[0] = insert_me;
        return;
    }
    if(array != NULL){
        sz = sz + 1;
        if(cap == sz){
            cap = sz*2;
        }
        T *temp = new T[sz];
        for(unsigned int i = 0; i < sz - 1 ; ++i){
            temp[i] = array[i];
        }
        temp[sz - 1] = insert_me;
        //Adjust insert_me if bigger than parent
        adjust_tree_insert(temp,sz - 1);

        delete []array;
        array = temp;
        return;
    }
}
template<typename T>
void Heap<T>::adjust_tree_insert(T* root, unsigned int index){
    cout << "!!!!!!!" << endl;
    int j = ((index - 1) / 2);
    if(root[j] > root[index]){
        cout <<"^^^^^" << endl;
        return;
    }
    if(root[index] > root[j]){
        cout << "#@#@@!!!!" << endl;
        T s = root[j];
        root[j] = root[index];
        root[index] = s;
        adjust_tree_insert(root,j);
    }
    return;
}
template<typename T>
void Heap<T>::adjust_tree_pop(T* root, unsigned int index){
    //cout << "Here67" << endl;
    //cout << "root[0] = " << root[0] << endl;
    int lc = index*2 + 1;
    int rc = index*2 + 2;
    if((lc == (sz - 1)) && (rc == sz)){
//        cout << "here1111111111111" << endl;
//        cout << "root[index] = " << root[index] << endl;
//        cout << "root[lc] = " << root[lc] << "    root[rc] = " << root[rc] << endl;
        if(root[lc] > root[index]){
            T temp;
            temp = root[index];
            root[index] = root[lc];
            root[lc] = temp;
            //cout << "rootAFTER[index] = " << root[index] << "rootAFTER[lc] = " << root[lc] << endl;
            return;
        }
        if(root[lc] <= root[index]){
            return;
        }
        return;
    }
    if(lc < sz && rc == sz - 1){
//        cout << "here222222222222" << endl;
//        cout << "root[index] = " << root[index] << endl;
//        cout << "root[lc] = " << root[lc] << "    root[rc] = " << root[rc] << endl;
        if(root[lc] > root[index]){
            T temp;
            temp = root[index];
            root[index] = root[lc];
            root[lc] = temp;
//            cout << "rootAFTER[index] = " << root[index] << "rootAFTER[lc] = " << root[lc] << endl;
            return;
        }
//        if(root[lc] <= root[index]){
//            return;
//        }
        if(root[rc] > root[index]){
            T temp;
            temp = root[index];
            root[index] = root[rc];
            root[rc] = temp;
//            cout << "rootAFTER[index] = " << root[index] << "rootAFTER[rc] = " << root[rc] << endl;
            adjust_tree_pop(root,index + 1);
            return;
        }
    }
    //THIS IS WHERE IF NOT LAST TWO CHECKS IN LIST BEGIN
    if(rc < sz - 1){
//        cout << "Got here 333333333333" << endl;
//        cout << "root[index] = " << root[index] << endl;
//        cout << "root[lc] = " << root[lc] << "    root[rc] = " << root[rc] << endl;
        if(root[lc] > root[index]){
            T temp;
            temp = root[index];
            root[index] = root[lc];
            root[lc] = temp;
//            cout << "rootAFTER[index] = " << root[index] << "rootAFTER[lc] = " << root[lc] << endl;
            adjust_tree_pop(root,index + 1);
            return;
        }
        if(root[rc] > root[index]){
            T temp;
            temp = root[index];
            root[index] = root[rc];
            root[rc] = temp;
//            cout << "rootAFTER[index] = " << root[index] << "rootAFTER[rc] = " << root[rc] << endl;
            adjust_tree_pop(root,index + 1);
            return;
        }
        adjust_tree_pop(root,index + 1);

    }
}
template<typename T>
T Heap<T>::Pop(){
    T capture;
    get_pop(capture);
    if(1 != sz){
        T *temp = new T[sz - 1];
        for(int i = 0; i < sz - 1; ++i){
            temp[i] = array[i + 1];
            //cout << "temp9999[" << i << "] = " << temp[i] << endl;
        }
        sz = sz - 1;
        delete []array;
        array = temp;
        for(int i = 0; i < sz; ++i){

            //cout << "arrary9999[" << i << "] = " << array[i] << endl;
        }
        adjust_tree_pop(array);
    //    for(int i = 0; i < sz; ++i){

    //        cout << "arrary45454545[" << i << "] = " << array[i] << endl;
    //    }
    }
    else if(1 == sz){
        delete []array;
        array = NULL;
        sz = 0;
    }
    return capture;
}
template<typename T>
T Heap<T>::get_pop(T& capture){
    capture = array[0];
    return capture;
}
template<typename T>
bool Heap<T>::is_empty() const{
    if(array == NULL){
        return true;
    }
}
template<typename T>
unsigned int Heap<T>::how_many(){
    return sz;
}
template<typename T>
unsigned int Heap<T>::size() const{
    return sz;
}
template<typename T>
unsigned int Heap<T>::capacity() const{
    return cap;
}
