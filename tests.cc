#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "list.h"

TEST_CASE( "Testing the SinglyLinkedList class" ) {
    SUBCASE( "Testing the constructor" ) {
        SinglyLinkedList<int> l;
        CHECK( l.size() == 0 );
    }

    SUBCASE( "Testing the constructor with initializer list") {
        SinglyLinkedList<int> l{ 1, 2, 3, 4 };
        CHECK( l.size() == 4 );
    }

    SUBCASE( "Testing push_back()" ) {
        SinglyLinkedList<int> l;
        l.push_back( 5 );
        CHECK( l.size() == 1 );
        CHECK( l.back() == 5 );
        CHECK( l.front() == 5 );

        l.push_back( 10 );
        CHECK( l.size() == 2 );
        CHECK( l.back() == 10 );
        CHECK( l.front() == 5 );

        l.push_back( 15 );
        CHECK( l.size() == 3 );
        CHECK( l.back() == 15 );
        CHECK( l.front() == 5 );
    }

    SUBCASE( "Testing pop_back()" ) {
        SinglyLinkedList<int> l = {5, 10, 15};
        CHECK( l.size() == 3 );
        CHECK( l.front() == 5 );
        CHECK( l.back() == 15 );

        l.pop_back();
        CHECK( l.size() == 2 );
        CHECK( l.front() == 5 );
        CHECK( l.back() == 10 );

        l.pop_back();
        CHECK( l.size() == 1 );
        CHECK( l.front() == 5 );
        CHECK( l.back() == 5 );

        l.pop_back();
        CHECK( l.size() == 0 );
    }

    SUBCASE( "Testing push_front()" ) {
        SinglyLinkedList<int> l;
        l.push_front( 5 );
        CHECK( l.size() == 1 );
        CHECK( l.front() == 5 );
        CHECK( l.back() == 5 );

        l.push_front( 10 );
        CHECK( l.size() == 2 );
        CHECK( l.front() == 10 );
        CHECK( l.back() == 5 );

        l.push_front( 15 );
        CHECK( l.size() == 3 );
        CHECK( l.front() == 15 );
        CHECK( l.back() == 5 );
    }

    SUBCASE( "Testing pop_front()" ) {
        SinglyLinkedList<int> l = {5, 10, 15};
        CHECK( l.size() == 3 );
        CHECK( l.front() == 5 );
        CHECK( l.back() == 15 );

        l.pop_front();
        CHECK( l.size() == 2 );
        CHECK( l.front() == 10 );
        CHECK( l.back() == 15 );

        l.pop_front();
        CHECK( l.size() == 1 );
        CHECK( l.front() == 15 );
        CHECK( l.back() == 15 );
        
        l.pop_front();
        CHECK( l.size() == 0 );
    }
}

TEST_CASE( "Tests involving the iterator class" ) {
    SUBCASE( "Testing range based 'for' loop" ) {
        SinglyLinkedList<int> l = {5, 10, 15};
        int expected_value = 5;
        for ( auto value : l ) {
            CHECK( expected_value == value );
            expected_value += 5;
        }
    }

    SUBCASE( "Testing insert()" ) {
        SinglyLinkedList<int> l;

    }
}