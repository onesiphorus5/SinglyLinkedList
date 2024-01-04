#include <initializer_list>
#include <iterator>

// For debugging
#include <iostream>

template <class T>
class SinglyLinkedList{
private:
    struct Node {
        Node( T value ) : t_value{value}, next{nullptr} {}

        T t_value;
        Node* next;
    };
    
    Node* head_node;
    Node* tail_node;
    std::size_t list_size;

    struct iterator{
        // Properties
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;

        // Shortand
        using value_type = Node;
        using pointer = Node*;
        using reference = Node&;

        // Constructor
        iterator( pointer ptr ) : t_ptr{ptr} {}

        // Operators
        bool operator!=( iterator iter ) {
            return this->t_ptr != iter.t_ptr;
        }
        iterator operator++() {
            this->t_ptr = this->t_ptr->next;
            return iterator( this->t_ptr );
        }
        T operator*() {
            return this->t_ptr->t_value;
        }

    private:
        pointer t_ptr;
    };


public:
    SinglyLinkedList();
    SinglyLinkedList( std::initializer_list<T> init_list );
    ~SinglyLinkedList();

    std::size_t size();

    void push_back( T value );
    void push_front( T value );

    void pop_back();
    void pop_front();

    const T& back();
    const T& front();

    void view_list(); // for debugging

    // TODO: implement insert()

    // iterator
    iterator begin() { return iterator( head_node ); }
    iterator end() { return iterator( nullptr ); }
};