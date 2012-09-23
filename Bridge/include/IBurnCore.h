#ifndef IBURNCORE_H_INCLUDED
#define IBURNCORE_H_INCLUDED

// implementor

class IBurnCore
{
public:
    virtual bool Burn(const char * files,int & error_code) = 0;
};

#endif // IBURNCORE_H_INCLUDED
