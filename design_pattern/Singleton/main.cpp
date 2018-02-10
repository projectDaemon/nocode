#include <iostream>
#include "../shared_include.h"

using namespace std;

class GlobalData
{
private:
    GlobalData():some_data_(0){}

    // just declare
    GlobalData(const GlobalData & );
    GlobalData & operator =(const GlobalData &);
public:
    static GlobalData & Instance()
    {
        static GlobalData inst;
        return inst;
    }

    int some_data()const {return some_data_;}
private:
    int some_data_;
};


int main()
{
    cout << GlobalData::Instance().some_data() <<endl;


    return 0;
}
