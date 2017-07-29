#ifndef XBURNCORE_H
#define XBURNCORE_H

#include "IBurnCore.h"

class XBurnCore
    : public IBurnCore
{
    public:
        XBurnCore();
        virtual ~XBurnCore();

        virtual bool Burn(const char * files,int & error_code);
};

#endif // XBURNCORE_H
