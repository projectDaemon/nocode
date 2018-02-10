// 读取lua脚本中的全局变量 
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

// read config file

void load_ui_conf(lua_State * L,const char * file_name,int * w,int * h)
{
	if(luaL_loadfile(L,file_name) || lua_pcall(L,0,0,0))
	{
		error(L,"can not run config file: %s",lua_tostring(L,-1));
	}

	lua_getglobal(L,"width");
	if(! lua_isnumber(L,-1))
	{
		error(L,"height should be a number");
	}
	*w = lua_tointeger(L,-1);

	lua_getglobal(L,"height");
	if(! lua_isnumber(L,-1))
	{
		error(L,"width should be a number");
	}
	*h = lua_tointeger(L,-1);
}



int _tmain(int argc, _TCHAR* argv[])
{
	lua_State * L = lua_open();
	luaL_openlibs(L);

	// read config file
	int w = 0 , h = 0;
	load_ui_conf(L,"E:\\research\\lua\\luavc\\lua515\\Debug\\ui.conf",& w, & h);

	printf("width = %d,height = %d\n",w,h);

	lua_close(L);
	return 0;
}

