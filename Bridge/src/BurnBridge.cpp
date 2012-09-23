#include "..\include\XBurnCore.h"
#include "..\include\BurnBridge.h"

BurnBridge::BurnBridge()
: burn_core_impl_(new XBurnCore())
{
    //ctor
}

BurnBridge::~BurnBridge()
{
    //dtor
}
bool BurnBridge::Burn(const char * files,int & error_code)
{
    return burn_core_impl_->Burn(files,error_code);
}
