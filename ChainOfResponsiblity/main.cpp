#include <iostream>
#include "../shared_include.h"

using namespace std;

struct DiscRequest
{
    std::string disc_serial_no;
};

class IPolicyCheck
{
public:
    virtual bool Check(const DiscRequest & request) = 0;
};

class AAAPolicyCheck : public IPolicyCheck
{
public:
    AAAPolicyCheck(IPolicyCheck * next)
    : next_checker_(next)
    {

    }

    virtual bool Check(const DiscRequest & request)
    {
        // check
        bool my_check_result = false;

        //
        //
        if(NULL == next_checker_)
            return true;
        if(my_check_result)
            return next_checker_->Check(request);
        else
            return false;
    }
protected:
    IPolicyCheck * next_checker_;
};

class BBBPolicyCheck : public IPolicyCheck
{
public:
    BBBPolicyCheck(IPolicyCheck * next)
    : next_checker_(next)
    {

    }

    virtual bool Check(const DiscRequest & request)
    {
        // check
        bool my_check_result = false;

        //
        if(NULL == next_checker_)
            return true;

        if(my_check_result)
            return next_checker_->Check(request);
        else
            return false;
    }
protected:
    IPolicyCheck * next_checker_;
};
// other policy checkers

class Monitor
{
public:
    Monitor(IPolicyCheck * checker)
    :policy_checker_(checker)
    {

    }
    void Start()
    {

    }

    void OnDiscEnter()
    {
        DiscRequest request;
        // fill request ..

        // Tell Chain
        policy_checker_->Check(request);
    }

private:
    IPolicyCheck * policy_checker_;
};

int main()
{
    Monitor m(new AAAPolicyCheck(new BBBPolicyCheck(NULL)));
    m.Start();

    return 0;
}
