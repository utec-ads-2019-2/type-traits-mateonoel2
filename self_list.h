#ifndef SELF_LIST_H
#define SELF_LIST_H

#include "node.h"

template <typename T>
class SelfList {
    public: 
        enum Method {
            Move, Count, Transpose
        };

    protected:
        Node<T>* head;
        Method method;
        int nodes = 0;

    public:
        SelfList(Method method) : head(nullptr) {
            this->method = method;
        };

        bool insert(T data) {
            auto node = new Node<T>(data);
            nodes++;
            if(head!=nullptr)
                node->next = head;
            head = node;
            return true;
        }
             
        bool remove(T data) {
            auto temp = head;
            int i=0;
            for(; i<size(); temp=temp->next, i++)
                if(data == temp->data)
                    break;

            if(i<size()){
                auto temp2 = head;
                for(; i>0; i--, temp2 = temp2->next)
                    temp2->next = temp2->next->next;
                delete temp;
                nodes--;
                }

            return i >= nodes;
        }  

        bool find(T data) {
            // No está funcionando de la manera correcta
            auto temp = head;
            bool ree = false;
            switch (method){
                case Move:{
                    // Mucho código repetido, pudiste haber sacado el bucle para llegar al elemento
                    for(int i = 0; i<size(); temp=temp->next, i++)
                        if(data == temp->data) {
                            swap(temp->data, head->data);
                            return true;
                        }
                    return false;
                }

                case Count:{
                    for(int i = 0; i<size(); temp=temp->next, i++){
                        if(data == temp->data) {
                            temp->contador++;
                            ree = true;
                            i = size()-1;
                        }
                    }
                    if(ree){
                        for(int j=1; j<size(); j++){
                            auto node = this->head;
                            for(int k=1; k<size()-j; node = node->next, k++){
                                if(node->contador > node->next->contador){
                                    swap(node->data, node->next->data);
                                }
                            }
                        }
                        reverse();
                    }
                    return ree;
                }

                case Transpose:
                    for(int i = 1; i<size();  temp=temp->next, i++) {
                        if (data == temp->next->data) {
                            swap(temp->data, temp->next->data);
                            return true;
                        }
                    }
                    return false;
            }
        }

        void reverse(){
            auto node1 = this->head;
            auto node2 = this->head;
            while(node2->next != nullptr){
                node2 = node2->next;
            }
            for(int i = 0;i<size()/2; node1 = node1->next, i++){
                swap(node1->data, node2->data);
                auto node_temp = node1;
                while(node_temp->next!=node2){
                    node_temp = node_temp->next;
                }
                node2 = node_temp;

            }
        }

        T operator [] (int index) {
            // Y las validaciones si es mayor o negativo?
            auto temp = head;
            if (index<size()){
                for(; index>0; temp=temp->next, index--){}
                return temp->data;
            }
        }
             
        int size() {
            return nodes;
        }

        void print() {
            auto temp = head;
            for(int i = 0; i<size(); temp=temp->next, i++){
                cout<<temp->data<<" ";
            }
        }

        ~SelfList() {
            if (head!=nullptr){
                head->killSelf();
            }
        }  
};

#endif