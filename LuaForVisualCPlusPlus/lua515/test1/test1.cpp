// ¼òµ¥µÄlua½âÊÍÆ÷
//

#include "stdafx.h"
#include <string>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "..\lua515\lua_inc.hpp"
#pragma comment(lib,"lua515_dll_md.lib")

int _tmain(int argc, _TCHAR* argv[])
{
	lua_State * L = lua_open();
	luaL_openlibs(L);

	char buff[256];
	int error;

	while(fgets(buff,sizeof(buff),stdin) != NULL)
	{
		error = luaL_loadbuffer(L,buff,strlen(buff),"tag") || lua_pcall(L,0,0,0);
		if(error)
		{
			fprintf(stderr,"%s",lua_tostring(L,-1));
			lua_pop(L,1);
		}
	}

	lua_close(L);
	return 0;
}

