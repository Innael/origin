#include <iostream>
#include "Spisok.cpp"
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>


List test;

TEST_CASE("Empty", "[test1]") {
    SECTION("Push Back") {
        test.PushBack(70);        
        INFO("PushBack work wrong");
        CHECK(test.PopBack() == 70);
    }
    SECTION("Push Front") {
        test.PushFront(10);
        INFO("PushFront work wrong");
        CHECK(test.PopFront() == 10);
    }

    SECTION("Pop Back") {
        test.PushBack(27);
        INFO("PopBack work wrong");
        CHECK(test.PopBack() == 27);
    }
    SECTION("Pop Front") {
        test.PushFront(32);
        INFO("PopFront work wrong");
        CHECK(test.PopFront() == 32);
    }

    SECTION("Work") {
        test.PushBack(72);
        test.PushBack(54);
        test.PushFront(31);
        test.PushFront(28);
        INFO("PB Work wrong");
        CHECK(test.PopBack() == 54);
        INFO("PB Work wrong");
        CHECK(test.PopBack() == 72);
        INFO("PF Work wrong");
        CHECK(test.PopFront() == 28);
        INFO("PF Work wrong");
        CHECK(test.PopFront() == 31);
    }
}


int main()
{
    return Catch::Session().run();
}