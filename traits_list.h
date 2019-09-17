#ifndef TRAITS_LIST_H
#define TRAITS_LIST_H

#include "node.h"

template <typename Tr>
class TraitsList {     
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
      
    private:
        Node<T>* head;
        Operation cmp;
        int nodes;

        bool find(T data, Node<T> **&pointer) {
            pointer = &head;
            while(*pointer!= nullptr){
                if(cmp((*pointer)->data,data)){
                    if(data==(*pointer)->data)
                        return true;
                }
                else{
                    return false;
                }
                pointer = &((*pointer)->next);
            }
            return false;
        }
              
    public:
        TraitsList() : head(nullptr), nodes(0){};
             
        bool insert(T data) {
            Node<T> **pointer;
            if(!find(data,pointer)){
                nodes++;
                auto node = new Node<T>(data);
                node->next = (*pointer);
                (*pointer) = node;
                return true;
            }
            return false;
        }
             
        bool remove(T data) {
            Node<T> **pointer = &head;
            if(find(data,pointer)){
                nodes--;
                Node<T>* temp = (*pointer);
                (*pointer) = (*pointer)->next;
                delete temp;
                return true;
            }
            return false;
        }  

        bool find(T data) {
            Node<T> **temp;
            return find(data,temp);
        }

        T operator [] (int index) {
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
            auto temp=head;
            for(int i=0;i < nodes;i++){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }

        ~TraitsList() {
            if (head!=nullptr){
                head->killSelf();
            }
        }         
};

#endif