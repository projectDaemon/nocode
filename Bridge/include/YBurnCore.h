#ifndef YBURNCORE_H
#define YBURNCORE_H

#include "IBurnCore.h"

class YBurnCore
    : public IBurnCore
{
    public:
        YBurnCore();
        virtual ~YBurnCore();

        virtual bool Burn(const char * files,int & error_code);
};

#endif // YBURNCORE_H
