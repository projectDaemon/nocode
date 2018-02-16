#include <iostream>

using namespace std;

class IBurn
{
public:
    virtual bool Burn() = 0;

};

class Burner : public IBurn
{
public:
    virtual bool Burn()
    {
        // direct call burn api
        return true;
    }
};

class BurnerDecorator : public IBurn
{
public:
    BurnerDecorator(IBurn * burner)
    : burner_(burner)
    {
    }
    virtual bool Burn()
    {
        // special operation

        bool res = burner_->Burn();

        // special operation

        return true;
    }

protected:
    IBurn * burner_;
};

int main()
{

    return 0;
}
