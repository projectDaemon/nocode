// µ÷ÓÃluaº¯Êý
//

#include "stdafx.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "..\lua515\lua_inc.hpp"
#pragma comment(lib,"lua515_dll_md.lib")
void error(lua_State * L ,const char * fmt,...)
{
	va_list argp;
	va_start(argp,fmt);
	vfprintf(stderr,fmt,argp);
	va_end(argp);

	lua_close(L);
	exit(EXIT_FAILURE);
}
double f(lua_State * L ,double x ,double y)
{
	double z;
	
	lua_getglobal(L,"f");
	lua_pushnumber(L,x);
	lua_pushnumber(L,y);

	if(lua_pcall(L,2,1,0) != 0)
		error(L,"error run function 'f' :%s",lua_tostring(L,-1));

	if(! lua_isnumber(L,-1))
		error(L,"function 'f' must return a number");

	z = lua_tonumber(L,-1);
	lua_pop(L,1);

	return z;
}
int _tmain(int argc, _TCHAR* argv[])
{
	lua_State * L = lua_open();
	luaL_openlibs(L);

	if(luaL_loadfile(L,"E:\\research\\lua\\luavc\\lua515\\Debug\\func.conf")|| lua_pcall(L,0,0,0))
	{
		error(L,"can not run config file: %s",lua_tostring(L,-1));
	}
	
	double res = f(L,1.0,2.0);
	printf("result = %lf\n",res);

	lua_close(L);
	return 0;
}

