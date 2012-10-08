#include <iostream>
#include "..\shared_include.h"
using namespace std;

class ProjectState
{
public:
    std::list<std::string> files_;
};

class ProjectOriginator;
// narrow public interface
class ProjectMemento
{
public:
    virtual ~ProjectMemento(){}
private:
    friend class ProjectOriginator;
    ProjectMemento(){}

    void set_state(const ProjectState & state){ state_ = state;}
    const ProjectState & state()const { return state_;}

private:
    ProjectState state_;
};

class ProjectOriginator
{
    ProjectOriginator();
public:
    ~ProjectOriginator(){}
    static ProjectOriginator & Instance()
    {
        static ProjectOriginator inst;
        return inst;
    }
    ProjectMemento* CreateMemento()
    {
        ProjectMemento* memento = new ProjectMemento();
        memento->set_state(state_);
        return memento;
    }
    void SetMemento(const ProjectMemento * memento)
    {
        state_ = memento->state();
    }

    bool Do()
    {
        return true;
    }
    bool Undo()
    {
        return true;
    }

private:
    ProjectState state_;
};

class ProjectCaretaker
{
public:
    bool Do()
    {
        memento_ = ProjectOriginator::Instance().CreateMemento();
        return ProjectOriginator::Instance().Do();
    }

    bool Undo()
    {
        ProjectOriginator::Instance().SetMemento(memento_);
        return ProjectOriginator::Instance().Undo();
    }
private:
    ProjectMemento* memento_;
};

int main()
{
    return 0;
}
