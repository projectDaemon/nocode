#include "../shared_include.h"
/*
Simple Factory
Abstract Factory
Factory Method
*/


class IBurnCore
{
public:
	virtual bool Burn(void * param) = 0;
	virtual bool Erase(void * param) = 0;
};
typedef shared_ptr<IBurnCore> IBurnCorePtr;


class BurnCoreX
	: public IBurnCore
{
public:
	virtual bool Burn(void * param) {return true;}
	virtual bool Erase(void * param) {return true;}
};
typedef shared_ptr<BurnCoreX> BurnCoreXPtr;

class BurnCoreY
	: public IBurnCore
{
public:
	virtual bool Burn(void * param) {return true;}
	virtual bool Erase(void * param) {return true;}
};
typedef shared_ptr<BurnCoreY> BurnCoreYPtr;

//////////////////////////////////////////////////////////////////////////
// Simple Factory
class BurnCoreFactory
{
public:
	enum BurnCoreType
	{
		BurnCoreType_X,
		BurnCoreType_Y,
	};
	static IBurnCorePtr Create(BurnCoreType type)
	{
		switch(type)
		{
		case BurnCoreType_X: return make_shared<BurnCoreX>();
		case BurnCoreType_Y: return make_shared<BurnCoreY>();
		}
		return IBurnCorePtr();
	}

};
//////////////////////////////////////////////////////////////////////////
// Factory Method
class IBurnCoreFactory
{
public:
	virtual IBurnCorePtr Create() = 0;
};
typedef shared_ptr<IBurnCoreFactory> IBurnCoreFactoryPtr;

class BurnCoreXFactory
	: public IBurnCoreFactory
{
public:
	virtual IBurnCorePtr Create()
	{
		return make_shared<BurnCoreX>();
	}
};
class BurnCoreYFactory
	: public IBurnCoreFactory
{
public:
	virtual IBurnCorePtr Create()
	{
		return make_shared<BurnCoreY>();
	}
};


int main()
{
	// Simple Factory
	{
		BurnCoreFactory::BurnCoreType type;
		type = BurnCoreFactory::BurnCoreType_X; // read from user config

		IBurnCorePtr core = BurnCoreFactory::Create(type);
		if(NULL != core.get())
		{
			core->Burn(NULL);
		}
	}

	// Factory Method
	{
		IBurnCoreFactoryPtr factory = make_shared<BurnCoreXFactory>();

		IBurnCorePtr core = factory->Create();

		core->Burn(NULL);
	}

	return 0;
}
