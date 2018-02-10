#include <iostream>
#include "version.h"



using namespace std;


int main(int argc, char const* argv[])
{
    cout << "Hello world! - " << Version::getBuildMachine() << endl;
}
