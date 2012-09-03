#include "..\shared_include.h"


class MyBurner;
class IMyburnerObserver
{
public:
	void NotifyProgress(double percent , MyBurner * burner)
	{

	}
};


class MyBurner
{
public:
	void Attach(IMyburnerObserver * observer){ observers_.push_back(observer);}
	void Detach(IMyburnerObserver * observer){ observers_.remove(observer);}

	bool StartBurn()
	{
		NotifyProgress(0.0);

		// detail progress

		NotifyProgress(1.0);

		return true;
	}

	void NotifyProgress(double percent)
	{
		for(std::list<IMyburnerObserver*>::iterator iter = observers_.begin();
			iter != observers_.end();
			++iter)
		{
			(*iter)->NotifyProgress(percent,this);
		}
	}

private:
	std::list<IMyburnerObserver*> observers_;
};

class UICaptionWindow
	: public IMyburnerObserver
{
public:

};

class UIBurnProgressWindow
	: public IMyburnerObserver
{
public:

};

int main()
{
	UICaptionWindow caption_window;
	UIBurnProgressWindow burn_progress_window;

	MyBurner burner;
	burner.Attach(& caption_window);
	burner.Attach(& burn_progress_window);

	burner.StartBurn();


	return 0;
}