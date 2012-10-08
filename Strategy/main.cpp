#include <iostream>
#include "..\shared_include.h"
using namespace std;

class ParamDialogContext
{
public:
    const std::string& disc_volume()const{return disc_volume_;}
private:
    std::string disc_volume_;
};

class ICheckStrategy
{
public:
    virtual bool Check(const ParamDialogContext & context) = 0;
};

class Iso9660CheckStrategy
{
public:
    virtual bool Check(const ParamDialogContext & context)
    {
        return true;
    }
};
class UdfCheckStrategy
{
public:
    virtual bool Check(const ParamDialogContext & context)
    {
        return true;
    }
};

class VolumeChecker
{
public:
    VolumeChecker(ICheckStrategy * strategy)
    : strategy_(strategy)
    {
    }

    bool Check()
    {
        return strategy_->Check(* context_);
    }
private:
    ICheckStrategy * strategy_;
    ParamDialogContext * context_;
};

int main()
{

    return 0;
}
