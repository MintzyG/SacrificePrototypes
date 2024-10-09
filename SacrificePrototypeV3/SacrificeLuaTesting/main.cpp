#include <iostream>
#include <cstdlib>
#include <lua.hpp>
#include <gtest/gtest.h>
#include "lua_integration.hpp"

#include "card.hpp"

int main(int argc, char **argv) {
  /// Initializing gtest
  ::testing::InitGoogleTest(&argc, argv);
  int test_results = RUN_ALL_TESTS();
  if (test_results) {
    std::cout << "A test has failed";
    exit(test_results);
  }

  std::cout << "Running your code";
  lua_State* L = init_lua();
  run_lua_function("test.lua");

  Card card;
  card.set_number(10);
  std::cout << card.get_number();

  lua_close(L);
  return test_results;
}

