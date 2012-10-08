#include <iostream>

using namespace std;

class IBurnDetector
{
public:
    virtual void OnEmptyDiscReady(bool is_ready) = 0;
};
class BurnDetector
{
public:
    void StartAsyncDetect(){}

private:
    IBurnDetector * detector_;
};
/////////////////////////////////////////////////////

class CButton
{
public:
    void Enable(bool b){}
    void Show(bool b){}
};

class CProgressBar
{
public:
    void Enable(bool b){}
    void Show(bool b){}
};

class IBurnerDialog
{
public:
    virtual void OnBurnButtonPushed() = 0;
};
class BurnerDialog
{
public:
    BurnerDialog()
    {

    }

    CButton button_start_burn_;
    CButton button_add_files_;
    CProgressBar progressbar_burn_;
};
////////////////////////////////////////////////

class BurnerUiMediator
    : public IBurnDetector
    , public IBurnerDialog
{
public:

    virtual void OnEmptyDiscReady(bool is_ready)
    {
        button_start_burn_->Enable(is_ready);
    }

    virtual void OnBurnButtonPushed()
    {
        button_add_files_->Enable(false);
        progressbar_burn_->Show(true);
    }

    void BindUiElement()
    {
        // bind to buttons , progressbar and list
    }

private:
    CButton * button_start_burn_;
    CButton * button_add_files_;
    CProgressBar * progressbar_burn_;
};

int main()
{

    return 0;
}
