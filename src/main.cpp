#include "Network.h"
#include "Functions.h"
#include <memory>
#include <iostream>

int main(){

    networkPtr net = networkPtr(new Network("settings.json"));

    doubleArray inputs = {
        0.3,
        0.2,
        0.1,
        0.8
    };

    Functions::printDoubleArray(net->feed(inputs));

    std::cout << "No errors!\n";

    return 0;

}