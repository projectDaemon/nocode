#include <iostream>
#include "../shared_include.h"


using namespace std;

int main()
{
    boost::shared_ptr<int> pint = boost::make_shared<int>();

    *pint = 1;

    cout << *pint << endl;


    return 0;
}
