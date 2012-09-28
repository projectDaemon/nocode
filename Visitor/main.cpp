#include <iostream>
#include "../shared_include.h"
using namespace std;

class IBurnItem;
class IBurnItemVisitor
{
public:
    virtual void Visit(IBurnItem * item) = 0;
};


class IBurnItem
{
public:
    void Accept(IBurnItemVisitor * visitor)
    {
        visitor->Visit(this);
    }

    const std::string & file_info()const{return file_info_;}
private:
    std::string file_info_;
};


class PrintVisitor : public IBurnItemVisitor
{
public:
    virtual void Visit(IBurnItem * item)
    {
        cout << item->file_info() <<endl;
    }

};

int main()
{
    //suppose below as a directory tree
    typedef std::list<IBurnItem*> DirectoryTree;

    DirectoryTree dir_tree;

    // some data insert into dir_tree

    PrintVisitor printor;
    for(DirectoryTree::iterator iter = dir_tree.begin();
    iter != dir_tree.end();
    ++iter)
    {
        (*iter)->Accept(&printor);
    }


    return 0;
}
