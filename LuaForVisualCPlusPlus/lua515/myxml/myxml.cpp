// myxml.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"


#include "..\lua515\lua_inc.hpp"
#pragma comment(lib,"lua515_dll_md.lib")

#include "..\expat\expat.h"
#pragma comment(lib,"expat.lib")

typedef struct taglxp_userdata
{
	lua_State * L;
	XML_Parser parser;
}lxp_userdata;

static void f_StartElement(void * ud,const char * name,const char ** atts);
static void f_CharData(void * ud,const char * s, int len);
static void f_EndElement(void * ud,const char * name);

static int lxp_make_parser(lua_State *L)
{
	// create and init
	lxp_userdata * xpu = (lxp_userdata *)lua_newuserdata(L, sizeof(lxp_userdata));
	xpu->parser = NULL;

	// metatable
	luaL_getmetatable(L,"Expat");
	lua_setmetatable(L,-2);

	// create parser
	XML_Parser p = xpu->parser = XML_ParserCreate(NULL);
	if(NULL == p)
		luaL_error(L,"xml parser create failed.");

	// environment
	luaL_checktype(L,1,LUA_TTABLE);
	lua_pushvalue(L,1); // table copy
	lua_setfenv(L,-2); // environment

	XML_SetUserData(p,xpu);
	XML_SetElementHandler(p,f_StartElement,f_EndElement);
	XML_SetCharacterDataHandler(p,f_CharData);

	return 1;
}

static int lxp_parse(lua_State * L)
{
	lxp_userdata * xpu = (lxp_userdata*)luaL_checkudata(L,1,"Expat");
	size_t len = 0;
	const char * s = luaL_optlstring(L,2,NULL,&len);

	// environment
	lua_settop(L,2);
	lua_getfenv(L,1);
	xpu->L = L;

	int status = XML_Parse(xpu->parser,s,(int)len,s == NULL);

	lua_pushboolean(L,status);

	return 1;
}



static int lxp_close(lua_State * L)
{
	lxp_userdata * xpu = (lxp_userdata*)luaL_checkudata(L,1,"Expat");
	
	if(xpu->parser)
		XML_ParserFree(xpu->parser);
	xpu->parser = NULL;
	return 0;
}
static void f_CharData(void * ud,const char * s, int len)
{
	lxp_userdata * xpu = (lxp_userdata*)ud;
	lua_State * L = xpu->L;

	lua_getfield(L,3,"CharacterData");
	if(lua_isnil(L,-1))
	{
		lua_pop(L,1);
		return;
	}

	lua_pushvalue(L,1);
	lua_pushlstring(L,s,len);
	lua_call(L,2,0);
}

static void f_EndElement(void * ud,const char * name)
{
	lxp_userdata * xpu = (lxp_userdata*)ud;
	lua_State * L = xpu->L;

	lua_getfield(L,3,"EndElement");
	if(lua_isnil(L,-1))
	{
		lua_pop(L,1);
		return;
	}

	lua_pushvalue(L,1);
	lua_pushstring(L,name);
	lua_call(L,2,0);
}

static void f_StartElement(void * ud,const char * name,const char ** atts)
{
	lxp_userdata * xpu = (lxp_userdata*)ud;
	lua_State * L = xpu->L;

	lua_getfield(L,3,"StartElement");
	if(lua_isnil(L,-1))
	{
		lua_pop(L,1);
		return;
	}

	lua_pushvalue(L,1);
	lua_pushstring(L,name);
	
	lua_newtable(L);
	for(; * atts; atts += 2)
	{
		lua_pushstring(L,*(atts + 1));
		lua_setfield(L,-2,*atts); // table[*atts] == *(atts + 1)
	}

	lua_call(L,3,0);
}

static const struct luaL_Reg lxp_meths[] = 
{
	{"parse",lxp_parse},
	{"close",lxp_close},
	{"__gc",lxp_close},
	{NULL,NULL}
};

static const struct luaL_Reg lxp_funcs[] = 
{
	{"new",lxp_make_parser},
	{NULL,NULL}
};


extern "C" __declspec(dllexport)
int luaopen_myxml(lua_State * L)
{
	luaL_newmetatable(L,"Expat");

	lua_pushvalue(L,-1);
	lua_setfield(L,-2,"__index");

	luaL_register(L,NULL,lxp_meths);
	luaL_register(L,"myxml",lxp_funcs);

	return 1;
}