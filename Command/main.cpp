#include <iostream>
#include "..\shared_include.h"
using namespace std;

class ICommand
{
public:
    virtual bool Execute() = 0;
    virtual bool Unexecute() = 0;
};
typedef boost::shared_ptr<ICommand> ICommandPtr;
typedef std::vector<ICommandPtr> ICommandPtrVector;

class InstallDriverCommand : public ICommand
{
public:
    virtual bool Execute()
    {
        // install driver service
        return true;
    }
    virtual bool Unexecute()
    {
        // remove driver service
        return true;
    }
};

class ModifyRegistryCommand : public ICommand
{
public:
    virtual bool Execute()
    {
        // add registry value
        return true;
    }
    virtual bool Unexecute()
    {
        // delete registry value
        return true;
    }
};

int main()
{
    ICommandPtrVector install_command_list;
    install_command_list.push_back(boost::make_shared<InstallDriverCommand>());
    install_command_list.push_back(boost::make_shared<ModifyRegistryCommand>());

    bool failed = false;
    std::vector<size_t> succeed_install_indexes;
    for(size_t i = 0; i < install_command_list.size(); ++i )
    {
        if(! install_command_list[i]->Execute())
        {
            failed = true;
            break;
        }
        succeed_install_indexes.push_back(i);
    }

    for(std::vector<size_t>::iterator iter = succeed_install_indexes.begin();
    iter != succeed_install_indexes.end();
    ++iter)
    {
        install_command_list[*iter]->Unexecute();
    }

    return 0;
}
