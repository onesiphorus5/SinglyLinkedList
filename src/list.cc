#include "list.h"
#include <iostream>

using namespace std;

template<class T>
SinglyLinkedList<T>::SinglyLinkedList() : 
    head_node{nullptr},
    tail_node{nullptr},
    list_size{0} {
}

template<class T>
SinglyLinkedList<T>::SinglyLinkedList( std::initializer_list<T> init_list ) {
    auto it = std::begin( init_list );
    auto it_end = std::end( init_list );
    this->head_node = new SinglyLinkedList<T>::Node{ *it };
    ++it;

    auto curr_node = this->head_node;
    for (; it != it_end; ++it ) {
        curr_node->next = new SinglyLinkedList<T>::Node( *it );
        curr_node = curr_node->next;
    }

    this->tail_node = curr_node;
    this->list_size = init_list.size();
}

template<class T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    auto curr_node = this->head_node;
    for ( ; curr_node != this->tail_node; ) {
        auto next_node = curr_node->next;

        delete curr_node;
        curr_node = next_node;
    }
    delete curr_node;

    this->head_node = nullptr;
    this->tail_node = nullptr;
    this->list_size = 0;
}

template<class T>
std::size_t SinglyLinkedList<T>::size() {
    return this->list_size;
}

template<class T>
void SinglyLinkedList<T>::push_back( T value ) {
    auto newNode = new SinglyLinkedList<T>::Node( value );
    if ( this->list_size == 0 ) {
        this->head_node = this->tail_node = newNode;
    } else {
        this->tail_node->next = newNode;
        this->tail_node = this->tail_node->next;
    }
    this->list_size += 1;
}

template<class T>
void SinglyLinkedList<T>::push_front( T value ) {
    auto newNode = new SinglyLinkedList<T>::Node( value );
    if ( this->list_size == 0 ) {
        this->head_node = this->tail_node = newNode;
    } else {
        newNode->next = this->head_node;
        this->head_node = newNode;
    }
    this->list_size += 1;
}

template<class T>
const T& SinglyLinkedList<T>::front() {
    return this->head_node->t_value;
}

template<class T>
const T& SinglyLinkedList<T>::back() {
    return this->tail_node->t_value;
}

template<class T>
void SinglyLinkedList<T>::pop_back() {
    if ( list_size == 0 ) {
        return;
    }
    if ( list_size == 1 ) {
        delete this->tail_node;
        this->head_node = this->tail_node = nullptr;
    } else if ( list_size == 2 ) {
        delete this->tail_node;
        this->tail_node = this->head_node;
    } else {
        auto curr_node = this->head_node;
        for ( ; curr_node != nullptr; curr_node = curr_node->next ) {
            if ( curr_node->next == this->tail_node ) {
                break;
            }
        }

        delete curr_node->next;
        this->tail_node = curr_node;
    }
    this->list_size -= 1;
}

template<class T>
void SinglyLinkedList<T>::pop_front() {
    if ( list_size == 0 ) {
        return;
    }
    if ( list_size == 1 ) {
        delete this->head_node;
        this->head_node = this->tail_node = nullptr;
    } else if ( list_size == 2 ) {
        delete this->head_node;
        this->head_node = this->tail_node;
    } else {
        auto next = this->head_node->next;

        delete this->head_node;
        this->head_node = next;
    }
    this->list_size -= 1;
}

template<class T>
void SinglyLinkedList<T>::view_list() {
    auto curr_node = this->head_node;
    for ( ; curr_node != nullptr; curr_node = curr_node->next ) {
        cout << curr_node->t_value;
        if ( curr_node->next != nullptr ) {
            cout << "-->";
        }
    }
    cout << endl;
}

template class SinglyLinkedList<int>;