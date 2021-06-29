// game.test.cpp created by alley on 2021-06-29 05:44:58.399141
#ifndef CATCH_INTERNAL_UNSUPPRESS_PARENTHESES_WARNINGS
#define CATCH_INTERNAL_UNSUPPRESS_PARENTHESES_WARNINGS
#endif
#include "catch.hpp"
#include "fakeit.hpp"
#include <game.h>
#include <glm/glm.hpp>

// tutorial: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md
// API Reference: https://github.com/catchorg/Catch2/blob/devel/docs/Readme.md
// FakeIt: https://github.com/eranpeer/FakeIt/wiki/Quickstart

Game game;
/* 
// TDD Format 
TEST_CASE("Define what you are testing", "[Game]"){
    SECTION( "you Can include Sub Sections" ) {}
    REQUIRE(true);
} */

// BDD Format
SCENARIO("Define what you are testing", "[Game]"){

   GIVEN("I am a developer"){
       WHEN("I add two numbers"){
           THEN("I should get the sume of the two numbers"){
               REQUIRE(2 + 2 == 4);
           }
       }
   }
}
