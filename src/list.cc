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
bool SinglyLinkedList<T>::empty() {
    return this->size() == 0;
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
typename SinglyLinkedList<T>::iterator SinglyLinkedList<T>::insert( 
    SinglyLinkedList<T>::iterator pos, T value ) {
    auto newNode = new SinglyLinkedList<T>::Node( value );
    // If the list is empty
    if ( this->empty() ) {
        this->head_node = this->tail_node = newNode;
        this->list_size += 1;
        return iterator( newNode );
    }
    
    this->list_size += 1;

    // If pos iterator points to the head node
    if ( pos == this->begin() ) {
        newNode->next = this->head_node;
        this->head_node = newNode;

        return iterator( newNode );
    }
    // If pos iterator points to one position past the tail node
    if ( pos == this->end() ) {
        this->tail_node->next = newNode;
        this->tail_node = newNode;

        return iterator( newNode );
    }

    // Find the iterator before the pos iterator
    auto iter = this->begin();
    for ( ; iterator( iter.t_ptr->next ) != pos; ++iter ) { ; }

    iter.t_ptr->next = newNode;
    newNode->next = pos.t_ptr;
    return iterator( newNode );
}

template<class T>
typename SinglyLinkedList<T>::iterator SinglyLinkedList<T>::erase( 
    SinglyLinkedList<T>::iterator pos ) {
    // If the list is empty
    if ( this->empty() ) {
        return this->end();
    }

    this->list_size -= 1;
    // If the list has only 1 element
    if ( this->size() == 1 ) {
        delete this->head_node;
        this->head_node = this->tail_node = nullptr;

        return this->end();
    }

    // If pos points to the head node
    if ( pos == this->begin() ) {
        auto head = this->begin().t_ptr;
        auto new_head = head->next;
        delete head;

        this->head_node = new_head;
        return this->begin();
    }

    // Find the iterator before the pos iterator
    auto iter = this->begin();
    for ( ; iterator( iter.t_ptr->next ) != pos; ++iter ) { ; }
    
    // If pos points to the tail node
    if ( pos == this->end() ) {
        auto new_tail = iter.t_ptr;
        delete this->tail_node;

        this->tail_node = new_tail;
        new_tail->next = nullptr;

        return this->end();       
    }

    auto node_to_delete = pos.t_ptr;
    auto prev_node = iter.t_ptr;
    prev_node->next = node_to_delete->next;
    delete node_to_delete;

    return iterator( prev_node->next );
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