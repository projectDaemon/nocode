#include <iostream>

using namespace std;

///////////////////////////
typedef void * BurnHandle;
class The3rdBurnCore
{
public:

    BurnHandle Open(char disk_letter)
    {
        BurnHandle handle;
        // inner core

        return handle;
    }

    int Burn(BurnHandle handle)
    {
        // inner operate with handle
        return 0; // 0 means succeed
    }
};

///////////////////////////
class The3rdBurnCoreAdapter
{
public:
    bool Burn(char disk_letter,int & error_code)
    {
        BurnHandle handle = core_.Open(disk_letter);
        if(NULL == handle)
        {
            error_code = -1;
            return false;
        }

        int res_burn = core_.Burn(handle);
        if(0 != res_burn)
        {
            error_code = res_burn;
            return false;
        }
        return true;
    }

private:
    The3rdBurnCore core_;
};



int main()
{
    return 0;
}
