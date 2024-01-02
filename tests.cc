#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "list.h"

TEST_CASE( "Just testing" ) {
    SinglyLinkedList<int> l;

    SUBCASE( "Test1" ) {
        CHECK( l.size() == 0 );
    }
}