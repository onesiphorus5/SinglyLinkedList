#include <initializer_list>

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
};