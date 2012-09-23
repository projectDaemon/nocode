#ifndef BURNBRIDGE_H
#define BURNBRIDGE_H

#include "IBurnCore.h"
#include "..\..\shared_include.h"

class BurnBridge
{
    public:
        BurnBridge();
        virtual ~BurnBridge();

        bool Burn(const char * files,int & error_code) ;
    private:
        boost::shared_ptr<IBurnCore> burn_core_impl_;
};

#endif // BURNBRIDGE_H
