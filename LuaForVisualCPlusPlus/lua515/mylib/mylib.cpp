// mylib.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "mylib.h"
#include "math.h"
#include "limits.h"

static int l_cos(lua_State * L)
{
	double d = luaL_checknumber(L,1); // first argument
	lua_pushnumber(L,cos(d)); // push first result
	return 1; // count of argument
}


//////////////////////////////////////////////////////////////////////////
#define BITS_PER_WORD	(CHAR_BIT * sizeof(unsigned int)) // 无符号整型的bit数
#define I_WORD(i)		((unsigned int)(i) / BITS_PER_WORD) // 存储i个bool值，需要多少个word。（第i个值在哪个位置上）
#define I_BIT(i)		(1 << ((unsigned int)(i) % BITS_PER_WORD)) // 索引i的掩码

typedef struct tagNumArray
{
	int size;
	unsigned int values[1];
}NumArray;

#define checkuarray(L) (NumArray*)luaL_checkudata(L,1,"LuaBook.array")
static int newarray(lua_State * L)
{
	int n = luaL_checkint(L,1);
	luaL_argcheck(L,n >= 1, 1,"invalid size");

	size_t nbytes = sizeof(NumArray) + I_WORD(n - 1) * sizeof(unsigned int);
	NumArray * a = (NumArray *)lua_newuserdata(L,nbytes);
	a->size = n;

	for(int i = 0;i <= I_WORD(n - 1); ++i)
		 a->values[i] = 0; // init all to zero

	luaL_getmetatable(L,"LuaBook.array");
	lua_setmetatable(L,-2);

	return 1;
}

static int setarray(lua_State * L)
{
	//NumArray * a = (NumArray *)lua_touserdata(L,1);
	NumArray * a = checkuarray(L);

	int index = luaL_checkint(L,2) - 1; // 索引1 转为 索引0
	luaL_checkany(L,3); // lua中任何值都可以转换为bool

	luaL_argcheck(L,a != NULL,1," 'array' expected");
	luaL_argcheck(L,0 <= index && index < a->size , 2, " index out of range");

	if(lua_toboolean(L,3))
		a->values[I_WORD(index)] |= I_BIT(index); // set to true
	else
		a->values[I_WORD(index)] &= ~I_BIT(index); // set to false
	return 0;
}

static int getarray(lua_State * L)
{
	//NumArray * a = (NumArray *)lua_touserdata(L,1);
	NumArray * a = checkuarray(L);
	int index = luaL_checkint(L,2) - 1;

	luaL_argcheck(L,a != NULL,1 ,"'array'expected");
	luaL_argcheck(L,0 <= index && index < a->size, 2," index out of range");

	lua_pushboolean(L,a->values[I_WORD(index)] & I_BIT(index));
	return 1;
}
static int getsize(lua_State * L)
{
	//NumArray * a = (NumArray *)lua_touserdata(L,1);
	NumArray * a = checkuarray(L);
	luaL_argcheck(L,a != NULL,1,"'array' expected");
	lua_pushinteger(L,a->size);
	return 1;
}
static int array2string(lua_State *L)
{
	NumArray * a = checkuarray(L);
	lua_pushfstring(L,"array(%d)",a->size);
	return 1;
}

//////////////////////////////////////////////////////////////////////////
static const struct luaL_Reg mylibs[] = 
{
	{"mycos",l_cos},
	{"new",newarray},
	{"set",setarray},
	{"get",getarray},
	{"size",getsize},
	{"__tostring",array2string},
	{NULL,NULL}
};
int luaopen_mylib( lua_State * L )
{
	luaL_newmetatable(L,"LuaBook.array");
	
	lua_pushvalue(L,-1);
	lua_setfield(L,-2,"__index");

	luaL_register(L,NULL,mylibs);
	luaL_register(L,"mylib",mylibs);
	return 1;
}
