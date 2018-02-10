#include <iostream>
#include "../shared_include.h"

using namespace std;

class BurnElementBase;
typedef boost::shared_ptr<BurnElementBase> BurnElementBasePtr;
typedef std::list<BurnElementBasePtr> BurnElementBasePtrList;

class BurnElementBase
{
public:
    BurnElementBasePtrList & children(){return children_;}

    void set_source_file_path(const std::string & str){source_file_path_ = str;}
    const std::string & source_file_path()const {return source_file_path_;}

    void set_target_file_path(const std::string & str){target_file_path_ = str;}
    const std::string & target_file_path()const { return target_file_path_;}

    virtual bool IsValidElement() = 0;
    virtual bool GetDescription() = 0;

protected:
    BurnElementBasePtrList children_;

    // basic field
    std::string source_file_path_;
    std::string target_file_path_;
};

class BurnElementFile : public BurnElementBase
{
public:
    virtual bool IsValidElement()
    {
        // use file api
        return true;
    }
    virtual bool GetDescription()
    {
        // use file api
        return true;
    }
};
class BurnElementDirectory: public BurnElementBase
{
public:
    virtual bool IsValidElement()
    {
        // use directory api
        return true;
    }
    virtual bool GetDescription()
    {
        // use directory api
        return true;
    }
};


int main()
{
    BurnElementBasePtr root = boost::make_shared<BurnElementDirectory>();

    return 0;
}
