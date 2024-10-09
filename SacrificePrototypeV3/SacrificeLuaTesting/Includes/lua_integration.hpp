#include <lua.hpp>

int sum(int, int);
int sum_wrapper(lua_State*);
lua_State* init_lua();
void run_lua_function(const char*);
