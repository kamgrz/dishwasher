#include "Dishwasher.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Dishwasher::Dishwasher()
{
}

Dishwasher::~Dishwasher()
{
}

void Dishwasher::start(){
    cout << "Washing..." << endl;
}

bool Dishwasher::stop(){
    cout << "Washing Stopped" << endl;
    return true;
}

void Dishwasher::pause(){
    cout << "Washing paused" << endl;
}
