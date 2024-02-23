#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include "random_parentheses.hpp" 

TEST_CASE("Parentheses are well-balanced", "[parentheses]") {
    RandomParenthesesGenerator rpg; 

    SECTION("Empty sequence is well-balanced") {
        REQUIRE(rpg.generate(0) == "");
    }

    SECTION("Single pair is well-balanced") {
        auto result = rpg.generate(1);
        REQUIRE(result == "()");
    }

    SECTION("Random sequence is well-balanced") {
        for (int i = 0; i < 10; ++i) {
            auto result = rpg.generate(10); 
            REQUIRE(rpg.isWellBalanced(result)); 
        }
    }
}

