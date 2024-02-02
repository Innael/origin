
#include <iostream>
#include "Spisok.cpp"
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>


List test;

TEST_CASE("Empty", "[test1]") {
    SECTION("EMPTY-f") {
        INFO("EMPTY-func-test-failed");
        CHECK(test.Empty() == true);       
    }
    SECTION("Size") {
        test.PushFront(20);
        test.PushFront(32);
        test.PushBack(70);
        INFO("WrongSize");
        CHECK(test.Size() == 3);
    }
    SECTION("Clear") {        
            test.Clear(); 
        INFO("Clear failed");
        CHECK(test.Size() == 0);
    }
}


int main()
{       
    return Catch::Session().run();    
}

