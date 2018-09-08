#ifndef SLIST_H
#define SLIST_H

#include "iterator.h"

template <class T>
class SListIterator : public Iterator<T> {     
    public: 
        SListIterator() : Iterator<T>() {};
        SListIterator(Node<T> *current) : Iterator<T>(current) {};
        SListIterator<T> operator++(){
            this -> current = this -> current -> next;
            retun *this;
        };
};

template <typename Tr>
class SList {     
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
        typedef SListIterator<T> iterator;
      
    private:
        Node<T>* head;
        Operation cmp;
              
    public:
        SList() {
            head = nullptr;
        };

        bool find(T search, Node<T> **&pointer) {
            if(head == NULL){throw("Lista Vacia");}
            else{
                while((*pointer)!=NULL){
                    if(cmp(search == (*pointer) -> data)){
                        if(search == (*pointer) -> data){return true;}
                        else{pointer =&((*pointer) -> next);}
                    }
                    else{return false;}
                }
                return false;
            }

        }
             
        bool insert(T data) {
            if(head == NULL){
                Node<T>* temporal = new Node<T> (data);
                temporal -> next = NULL;
                head = temporal;
                return true;
            }

        }
             
        bool remove(T item) {
            if(head == NULL){throw "Lista Vacia";}

        }  
             
        iterator begin() {
            return iterator(this -> head);

        }
             
        iterator end() {
            Node<T>* temporal = head;

        }
             
        ~SList() {
            if (head) {
                head->killSelf();
            } 
        }         
};

#endif