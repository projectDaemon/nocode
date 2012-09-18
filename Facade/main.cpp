#include "..\shared_include.h"
#include "BurnCoreXAPI.h"

class BurnCoreXFacade
{
public:
	static bool Burn(char letter,const std::list<std::string> & files)
	{
		// 这里调用api函数，给最终用户屏蔽复杂api的调用
		if( 0 != burncorex_init())
			return false;

		void * handle = burncorex_opendisc(letter);
		if( 0 == handle)
			return false;

		std::string str_files;
		// todo: convert files list to str_files

		if( 0 == burncorex_burnfiles(handle,str_files.c_str()))
			return false;

		burncorex_close(handle);
		burncorex_uninit();

		return true;
	}
};

int main()
{
	// just call BurnCoreXFacade::Burn

	return 0;
}