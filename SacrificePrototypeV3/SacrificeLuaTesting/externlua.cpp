#include <lua.hpp>
#include <iostream>
#include <gtest/gtest.h>

lua_State* GlobalState;

int sum(int a, int b) {
  return a + b;
}

TEST(SumTest, PositiveNumbers) {
    EXPECT_EQ(sum(1, 2), 3);
    EXPECT_EQ(sum(10, 20), 30);
}

TEST(SumTest, NegativeNumbers) {
    EXPECT_EQ(sum(-1, -2), -3);
    EXPECT_EQ(sum(-10, -20), -30);
}

TEST(SumTest, MixedSignNumbers) {
    EXPECT_EQ(sum(-1, 1), 0);
    EXPECT_EQ(sum(-10, 20), 10);
}

int sum_wrapper(lua_State *L) {
  int a = luaL_checkinteger(L, 1);
  int b = luaL_checkinteger(L, 2);
  int result = sum(a, b);
  lua_pushinteger(L, result);
  return 1;
}

void run_lua_function(const char* filename) {
  char result[100];
  sprintf(result, "%s%s", "lua/", filename);

  if (luaL_dofile(GlobalState, result) != LUA_OK) {
    std::cerr << "Error: " << lua_tostring(GlobalState, -1) << std::endl;
    lua_pop(GlobalState, 1);
    exit(1);
  }
}

lua_State* init_lua() {
  lua_State *L = luaL_newstate();
  GlobalState = L;
  luaL_openlibs(L);

  lua_register(L, "sum", sum_wrapper);

  return L;
}

