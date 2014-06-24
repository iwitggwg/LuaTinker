#include <iostream>

extern "C" 
{
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
};

#include "lua_tinker.h"

int cpp_func(int arg1, int arg2)
{
	return arg1 + arg2;
}

int main()
{
	//lua_State* L = lua_open();
	lua_State* L = luaL_newstate();

	//luaopen_base(L);
	luaL_requiref(L, "_G", luaopen_base, 1);
    lua_pop(L, 1);

    lua_tinker::beginmodule(L);
      lua_tinker::beginmodule(L, "mod1");
        lua_tinker::beginmodule(L, "mod11");
	      lua_tinker::def(L, "cpp_func", cpp_func);
        lua_tinker::endmodule(L);
      lua_tinker::endmodule(L);
    lua_tinker::endmodule(L);

	lua_tinker::dofile(L, "sample1.lua");

	int result = lua_tinker::call<int>(L, "lua_func", 3, 4);

	printf("lua_func(3,4) = %d\n", result);

	lua_close(L);

	return 0;
}
