#include "Engine.h"

using namespace std;

int main()
{
    Engine system;
    while(!system.exit())
    {
        system.start();
    }
    return 0;
}
