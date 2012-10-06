#include <iostream>

using namespace std;


class BurnCore
{
public:
    bool BurnFiles(const char * files,int & error)
    {
        return true;
    }
    bool BurnImage(const char * image_path,int & error)
    {
        return true;
    }
};

class BurnUser
{
public:
    bool CanBurnFiles()const{return true;}
    bool CanBurnImage()const{return true;}
};

class BurnCoreProxy
{
public:
    bool BurnFiles(const char * files,int & error)
    {
        if(! user_.CanBurnFiles())
            return false;

        // burn

        return true;
    }
    bool BurnImage(const char * image_path,int & error)
    {
        if(! user_.CanBurnImage())
            return false;

        // burn

        return true;
    }
    void set_user(const BurnUser & user){user_ = user;}
private:
    BurnUser user_;
};

int main()
{
    BurnUser user;
    BurnCoreProxy proxy;
    proxy.set_user(user);

    int error = 0;
    proxy.BurnFiles("c:\\1.txt",error);


    return 0;
}
