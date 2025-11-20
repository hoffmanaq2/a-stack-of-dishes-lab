#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/dishstack.hpp"

TEST_CASE("New stack starts empty") {
    DishStack stack;
    REQUIRE(stack.size() == 0);
}

TEST_CASE("Push increases stack size and peek shows top") {
    DishStack stack;
    Dish d1("First");
    Dish d2("Second");

    stack.push(d1);
    REQUIRE(stack.size() == 1);
    REQUIRE(stack.peek().get_description() == "First");

    stack.push(d2);
    REQUIRE(stack.size() == 2);
    REQUIRE(stack.peek().get_description() == "Second");
}

TEST_CASE("Pop returns top and decreases size") {
    DishStack stack;
    Dish d1("First");
    Dish d2("Second");

    stack.push(d1);
    stack.push(d2);

    Dish popped = stack.pop();
    REQUIRE(popped.get_description() == "Second");
    REQUIRE(stack.size() == 1);

    Dish popped2 = stack.pop();
    REQUIRE(popped2.get_description() == "First");
    REQUIRE(stack.size() == 0);
}

TEST_CASE("Pop from empty returns empty Dish and size unchanged") {
    DishStack stack;
    Dish popped = stack.pop();
    REQUIRE(popped.get_description() == ""); // empty return value
    REQUIRE(stack.size() == 0);
}

TEST_CASE("Peek on empty returns empty Dish and size unchanged") {
    DishStack stack;
    Dish peeked = stack.peek();
    REQUIRE(peeked.get_description() == "");
    REQUIRE(stack.size() == 0);
}

TEST_CASE("Cannot push when full") {
    DishStack stack;
    // Fill stack up to internal MAX_SIZE (10)
    for (int i = 0; i < 10; i++)
        stack.push(Dish("Dish " + std::to_string(i)));

    REQUIRE(stack.size() == 10);

    // Push one more — should not change size
    stack.push(Dish("Overflow attempt"));
    REQUIRE(stack.size() == 10);

    // Top item should still be Dish 9
    REQUIRE(stack.peek().get_description() == "Dish 9");
}
