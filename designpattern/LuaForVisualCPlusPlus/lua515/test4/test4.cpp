// ��ȡlua�ű���table��keyֵ 
//

#include "stdafx.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "..\lua515\lua_inc.hpp"
#pragma comment(lib,"lua515_dll_md.lib")
// global 
void error(lua_State * L ,const char * fmt,...)
{
	va_list argp;
	va_start(argp,fmt);
	vfprintf(stderr,fmt,argp);
	va_end(argp);

	lua_close(L);
	exit(EXIT_FAILURE);
}

int getfield(lua_State * L,const char * key)
{
	lua_pushstring(L,key);
	lua_gettable(L,-2);// pushstring ֮��table��λ������-2�ˡ�

	if(!lua_isnumber(L,-1))
		error(L,"invalid value in background color");

	int result = (int)lua_tonumber(L,-1);
	lua_pop(L,1); // ����һ��Ԫ�أ�������lua_gettable�Ľ�������ִ����֮��-1����table�ˡ�
	return result;
}
int getfield_new(lua_State * L,const char * key)
{
	lua_getfield(L,-1,key);// ��table�����������lua_pushstring & lua_gettable
	if(!lua_isnumber(L,-1))
		error(L,"invalid value in background color");

	int result = (int)lua_tonumber(L,-1);
	lua_pop(L,1); // ����һ��Ԫ�أ�������lua_getfield�Ľ�������ִ����֮��-1����table�ˡ�
	return result;
}
int _tmain(int argc, _TCHAR* argv[])
{
	lua_State * L = lua_open();
	luaL_openlibs(L);

	if(luaL_loadfile(L,"E:\\research\\lua\\luavc\\lua515\\Debug\\uitable.conf") || lua_pcall(L,0,0,0))
	{
		error(L,"can not run config file: %s",lua_tostring(L,-1));
	}
	// read table
	lua_getglobal(L,"background");
	if(! lua_istable(L,-1))
		error(L,"'background' is not a table.");

	int red = getfield_new(L,"r");
	int green = getfield_new(L,"g");
	int blue = getfield_new(L,"b");

	printf("%d,%d,%d\n",red,green,blue);

	lua_close(L);
	return 0;
}

