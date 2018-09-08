#ifndef DLIST_H
#define DLIST_H

#include "iterator.h"

template <typename T>
class DListIterator : public Iterator<T> {     
    public: 
        DListIterator() : Iterator<T>() {};
        DListIterator(Node<T> *current) : Iterator<T>(current) {};
        DListIterator<T> operator++(){
            this -> current = this -> current -> next;
            return *this;
        };
        DListIterator<T> operator--(){
            this -> current = this -> current -> prev;
            return *this;
        };
};

template <typename Tr>
class DList {     
    public:
        typedef typename Tr::T T;
        typedef DListIterator<T> iterator;
      
    private:
        Node<T>* head;
        Node<T>* tail;
              
    public:
        DList() {
            head = tail = nullptr;
        };

        void push_front(T data) {
            Node<T>*temporal = new Node<T>(data);
            if(head == NULL){head = tail = temporal;}
            else{
                head -> prev = temporal;
                temporal -> next = head;
                head = temporal;
            }
            nodes++;
        }

        void push_back(T data) {
            Node<T>*temporal = new Node<T>(data);
            if(head == NULL){head = tail = temporal;}
            else{
                tail -> next = temporal;
                temporal -> prev = tail;
                tail = temporal;
            }
            nodes++;
        }
             
        void pop_front() {
            if(head == NULL){throw "Lista Vacia";}
            else{
                Node<T>* temporal = head;
                head = head -> next;
                delete temporal;
            }
            nodes--;
        }
             
        void pop_back() {
            if(head == NULL){throw "Lista Vacia";}
            else{
                Node<T>* temporal = tail;
                tail = tail -> prev;
            }
            nodes--;
        }
             
        iterator begin(){return DListIterator(this -> head);}
             
        iterator end(){return DListIterator(this -> tail);}
             
        ~DList() {
            if (head) {
                head->killSelf();
            } 
        }         
};

#endif