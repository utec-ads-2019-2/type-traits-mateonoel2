#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    int contador;
    Node<T>* next;
    explicit Node(T data) : data(data) {
        next = nullptr;
        contador = 0;
    }
      
    void killSelf();
};

template <typename T>
void Node<T>::killSelf() {
    if (next) {
        next->killSelf();
    }
    delete this;
}

#endif