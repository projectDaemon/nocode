#include <iostream>
#include "include\BurnBridge.h"
using namespace std;

int main()
{
    BurnBridge burn_bridge;
    int error_code = 0;
    burn_bridge.Burn("c:\\myfile.txt",error_code);

    return 0;
}
